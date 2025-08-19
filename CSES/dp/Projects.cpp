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

struct Prj { ll s; ll e; ll r; };

int main() {
    ll n; cin >> n;
    vec<Prj> a(n);
    FOR(i, 0, n-1) {
        ll s, e, r; cin >> s >> e >> r;
        a[i] = {s, e, r};
    }
    sort(a.begin(), a.end(),
        [](const Prj &a, const Prj &b) {
            return a.e < b.e;
        });
    vl p(n, -1);
    FOR(i, 0, n-1) {
        ll l=0, h=i-1, best=-1;
        while (l<=h) {
            ll m = (l+h)/2;
            if (a[m].e < a[i].s) {
                best=m;
                l=m+1;
            } else {
                h=m-1;
            }
        }
        p[i]=best;
    }

    vl dp(n+1, 0);
    FOR(i, 1, n) {
        dp[i]=max(dp[i-1], dp[p[i-1] + 1] + a[i-1].r);
    }
    println(dp[n]);
    return 0;
}

