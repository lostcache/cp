#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>
#define ll long long
#define vec vector
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define FOR(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (ll i = (a); i >= (b); --i)
#define SORT(a) sort((a).begin(), (a).end())
#define println(a) (cout << (a) << endl)
#define print(a) (cout << (a))
#define REV(a) reverse((a).begin(), (a).end())
const int inf = 1e9;
const ll ll_inf = 1e18;
const ll MOD = 1e9 + 7;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const char cdirs[4] = {'R', 'L', 'D', 'U'};

using namespace std;

struct FastIO {
  FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} fastio_init;

struct Edge {
    ll f, t, w;
};

int main() {
    ll n, m; cin >> n >> m;
    vec<Edge> edges(m);
    vvl adj(n+1);
    FOR(i, 0, m-1) {
        ll f, t, w; cin >> f >> t >> w;
        edges[i]={f, t, -w};
        adj[f].pb(t);
    }
    vl dist(n+1, ll_inf);
    dist[1]=0;

    FOR(i, 1, n-1) {
        for (auto &e: edges) {
            if (dist[e.f] < ll_inf && dist[e.f] + e.w < dist[e.t]) {
                dist[e.t] = dist[e.f]+ e.w;
            }
        }
    }

    vl affected;
    for (auto &e: edges) {
        if (dist[e.f] < ll_inf && dist[e.f]+e.w<dist[e.t]) {
            affected.pb(e.t);
        }
    }

    vl vst(n+1, 0);
    queue<ll> q;
    for (auto v: affected) {
        vst[v]=true;
        q.push(v);
    }

    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (auto n: adj[u]) {
            if (vst[n]) continue;
            vst[n]=true;
            q.push(n);
        }
    }

    if (vst[n]) println(-1);
    else println(-dist[n]);
    return 0;
}

