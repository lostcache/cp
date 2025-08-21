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

struct Flight {
  ll f, t, c;
};

int main() {
  ll n, m, k; cin >> n >> m >> k;
  vec<vec<Flight>> adj(n+1);
  FOR(i, 1, m) {
    ll ff, t, c; cin >> ff >> t >> c;
    adj[ff].pb({ff, t, c});
  }

  vl res; res.reserve(k);
  vl f(n+1);

  priority_queue<pll, vec<pll>, greater<pll>> pq;
  pq.push({0, 1});
  while (!pq.empty() && res.size() < k) {
    auto [ci, ni] = pq.top(); pq.pop();
    if (f[ni] == k) continue;
    ++f[ni];
    if (ni == n) {
      res.pb(ci);
      if (res.size() == k) break;
    }

    for (auto [_, n, c]: adj[ni]) {
      if (f[n] == k) continue;
      pq.push({ci+c, n});
    }
  }

  FOR(i, 0, k-1) {
    if (i) cout << ' ';
    cout << res[i];
  }
  cout << endl;
  return 0;
}

