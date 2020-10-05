#include <bits/stdc++.h>

using namespace std;

#define ll		long long int
#define pll		pair<ll, ll>
#define pb		push_back


class comp{
public:
    bool operator() (pll p1, pll p2) {
        return p1.f > p2.f;
    }
};

void solve() {
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

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist(n, INF);
    dist[0] = 0;

    pq.push({0, 0});

    vector<ll> parent(n, -1);

    while(!pq.empty()) {
        ll v = pq.top().s;
        ll d_v = pq.top().f;
        pq.pop();
        if(d_v != dist[v])
            continue;
        for(pll ei : edges[v]) {
            ll to = ei.f;
            ll wt = ei.s;
            if(d_v + wt < dist[to]) {
                dist[to] = d_v + wt;
                parent[to] = v;
                pq.push({dist[to], to});
            }
        }
    }

    vector<ll> path;
    if(dist[n - 1] == INF) {
        cout << -1 << endl;
    } else {
        --n;
        while(parent[n] != -1) {
            path.pb(n + 1);
            n = parent[n];
        }
        path.pb(1);
        reverse(all(path));
        for(ll i : path) {
            cout << i << " ";
        }
        cout << endl;
    }

}

int main() {
    fastio;
    solve();
}
