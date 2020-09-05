class UF {
public:
    vector<int> parent;
    int numComponents;

    UF(int n) {
        parent.resize(n + 1, -1);
        numComponents = n;
    }

    int find(int x) {
        int root = x;
        while(parent[root] >= 0) {
            root = parent[root];
        }

        // Path Compression
        while(parent[x] >= 0) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }

        return root;
    }

    void unionz(int x, int y) {
        int root1 = find(x);
        int root2 = find(y);

        if(root1 == root2)
            return;

        if(parent[root1] < parent[root2]) {
            parent[root1] += parent[root2];
            parent[root2] = root1;
        } else {
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }

        numComponents--;
    }
};