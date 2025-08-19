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

int modpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp%2) res=(res*base)%MOD;
        base=(base*base)%MOD;
        exp>>=1;
    }
    return res;
}

int main() {
    ll n; cin >> n;
    ll sum=(n*(n+1))/2;
    if (sum%2) { println(0); return 0; }
    ll tar=sum/2;
    vl dp(tar+1, 0); dp[0]=1;
    FOR(i, 1, n) {
        FORD(j, tar, 0) {
            if (j-i < 0) break;
            dp[j]=(dp[j]+dp[j-i])%MOD;
        }
    }
    println(dp[tar]*modpow(2, MOD-2)%MOD);
    return 0;
}

