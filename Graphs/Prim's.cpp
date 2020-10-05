#include <iostream>
#include <algorithm>
#include <vector>
//#include <unordered_map>
//#include <map>
#include <queue>
//#include <cstring>

//#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}


#define MOD		1000000007
#define ll		long long int
#define pll		pair<ll, ll>
#define pb		push_back
#define endl	"\n"
#define f 		first
#define s 		second
#define fastio 	ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(v)  (v).begin(), (v).end()
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define INF 1000000000000000000

ll power(ll x, ll y) { ll ans = 1; x %= MOD; while (y) {if (y & 1)ans = (x * ans) % MOD; x = (x * x) % MOD; y >>= 1;} return ans;}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

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
