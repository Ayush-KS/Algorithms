#include <bits/stdc++.h>
#define INF (int)1e7
using namespace std;

void floydWarshall(int n, vector<vector<int>>& edges) {
    vector<vector<int>> dp = edges;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    cout << "\nAll pairs shortest path:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Shortest path from " << i << " to " << j << " is:";
            if(dp[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dp[i][j];
            }
            cout << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(n, INF));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            string wt;
            cin >> wt;
            if(wt == "INF")
                continue;
            else
                edges[i][j] = stoi(wt);
        }
    }

    floydWarshall(n, edges);
}