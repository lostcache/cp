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


int main() {
    ll n; cin >> n; vl a(n); FOR(i, 0, n-1) cin >> a[i];
    ll mx = accumulate(a.begin(), a.end(), 0LL);
    vl dp(mx+1, 0); dp[0]=1;
    for (auto ai: a) {
        FORD(i, mx, 1) {
            if (i-ai<0) continue;
            dp[i] += dp[i-ai];
        }
    }
    vl res;
    FOR(i, 1, mx) {
        if (dp[i]) res.pb(i);
    }
    println(res.size());
    FOR(i, 0, res.size()-1) {
        print(res[i]);
        print(i==res.size()-1?"\n":" ");
    }
    return 0;
}
