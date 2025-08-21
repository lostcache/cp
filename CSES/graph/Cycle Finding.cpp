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
  vec<Edge> e(m+1);
  FOR(i, 1, m) { 
    ll f, t ,c;
    cin >> f >> t >> c;
    e[i]={f, t, c}; 
  }
  
  vl dist(n+1, 0);
  vl paren(n+1, -1);
  ll updatedNode=-1;
  FOR(i, 1, n) {
    updatedNode=-1;
    for (const Edge &ei: e) {
      if (dist[ei.f]+ei.w<dist[ei.t]) {
        dist[ei.t]=max(-ll_inf, dist[ei.f]+ei.w);
        paren[ei.t]=ei.f;
        updatedNode=ei.t;
      }
    }
  }

  if (updatedNode==-1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    ll cycleNode = updatedNode;
    FOR(i, 1, n) { cycleNode = paren[cycleNode]; }
    vl cycle;
    ll start=cycleNode;
    cycle.pb(start);
    for (ll v=paren[start]; v!=start; v=paren[v]) {
      cycle.pb(v);
    }
    cycle.pb(start);
    REV(cycle);
    for (auto v: cycle) {
      cout << v << " ";
    }
    cout << "\n";
  }
  return 0;
}

