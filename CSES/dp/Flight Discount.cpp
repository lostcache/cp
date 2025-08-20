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

struct Cmp {
  bool operator()(const pll &a, const pll &b) {
    return get<1>(a) > get<1>(b);
  }
};

struct Edge {
  ll f, t, c;
};

int main() {
  ll n, m; cin >> n >> m;
  vec<vec<Edge>> adj(n+1);
  FOR(i, 1, m) {
    ll f, t, c; cin >> f >> t >> c;
    adj[f].pb({f, t, c});
  }

  vec<pll> paren(n+1, {-1, -1});
  vvl dist(n+1, vl(2, ll_inf)); dist[1][0]=0;
  priority_queue<pll, vec<pll>, Cmp> pq;
  pq.push({1*2+0, 0});

  while (!pq.empty()) {
    auto [node_code, cost] = pq.top(); pq.pop();
    ll node=node_code/2, used=node_code%2;
    if (cost>dist[node][used]) continue;
    for (auto &e: adj[node]) {
      if (cost+e.c<dist[e.t][used]) {
        dist[e.t][used]=e.c+cost;
        pq.push({e.t*2+used, dist[e.t][used]});
      }
      if (!used) {
        if (cost+e.c/2<dist[e.t][1]) {
          dist[e.t][1]=cost+e.c/2;
          pq.push({e.t*2+1, dist[e.t][1]});
        }
      }
    }
  }
  println(min(dist[n][0], dist[n][1]));
  return 0;
}

