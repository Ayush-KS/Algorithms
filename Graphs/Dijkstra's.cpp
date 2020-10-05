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

void dijkstra(ll n, vector<vector<pll>> edges, int s) {
    vector<ll> parent(n, -1);
    vector<ll> dist(n, INF);

    dist[s] = 0;
    set<pll> st;
    st.insert({0, s});

    while(!st.empty()) {
        ll curr = st.begin() -> s;
        st.erase(st.begin());

        for(pll ei : edges[curr]) {
            ll to = ei.f;
            ll wt = ei.s;

            if(wt + dist[curr] < dist[to]) {
                st.erase({dist[to], to});
                dist[to] = wt + dist[curr];
                parent[to] = curr;
                st.insert({dist[to], to});
            }
        }
    }

    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << "Minimum distance from " << s + 1 << " to " << i + 1 << " is: ";
        cout << dist[i] << endl;
        int j = i;
        cout << "The minimum distance path is:\n";
        while(parent[j] != -1) {
            cout << j + 1 << ' ';
            j = parent[j];
        }
        cout << j + 1 << endl;
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> edges(n, vector<pll>());
    ll x, y, w;

    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        --x, --y;
        edges[x].pb({y, w});
        edges[y].pb({x, w});
    }

    dijkstra(n, edges, 0);
}
