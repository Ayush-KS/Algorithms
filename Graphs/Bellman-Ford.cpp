#include <iostream>
#include <set>
#include <vector>

#define ll long long int
#define pll pair<ll, ll>
#define INF (ll)1e18
#define f first
#define s second
#define pb		push_back

using namespace std;

class edge {
public:
    ll from, to, wt;
    edge(ll f, ll t, ll w) {
        from = f;
        to = t;
        wt = w;
    }
};

void bellmanFord(ll n, vector<edge> edges, ll s) {
    vector<ll> dist(n, INF);
    dist[s] = 0;

    for(int i = 0; i < n; i++) {
        for(edge ed : edges) {
            if(dist[ed.from] + ed.wt < dist[ed.to]) {
                dist[ed.to] = dist[ed.from] + ed.wt;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(edge ed : edges) {
            if(dist[ed.from] + ed.wt < dist[ed.to]) {
                cout << "There is a negative cycle in the graph!\n";
                return;
            }
        }
    }

    cout << "\nVertex\tDistance\n";
    for(int i = 0; i < n; i++) {
        cout << i << "\t" << dist[i] << endl;
    }

}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<edge> edges;
    ll x, y, w;

    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        edges.pb(edge(x, y, w));
    }

    bellmanFord(n, edges, 0);
}

//5 8
//0 1 -1
//0 2 4
//1 2 3
//1 3 2
//1 4 2
//3 2 5
//3 1 1
//4 3 -3
