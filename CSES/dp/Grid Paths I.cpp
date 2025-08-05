#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

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
#define vll vector<pll>
#define pb push_back
#define FOR(i, a, b) for(ll i=(a); i<(b); ++i)
#define FORD(i, a, b) for(ll i=(a); i>(b); --i)
#define SORT(a) sort((a).begin(), (a).end());
#define println(a) cout << (a) << endl;
#define print(a) cout << (a);

const ll MOD = 1e9+7;
const int inf = 1e9;
const ll ll_inf = 1e18;

using namespace std;

int main() {
    ll n; cin >> n;
    vec<string> map(n); FOR(i, 0, n) { cin >> map[i]; }
    if (map[n-1][n-1] == '*') { println(0); return 0; }
    vvl dp(n, vl (n, 0)); dp[n-1][n-1] = 1;
    FORD(i, n-1, -1) {
        FORD(j, n-1, -1) {
            if (map[i][j] == '*') continue;
            ll r=0, d=0;
            if (j+1 < n) r = dp[i][j+1];
            if (i+1 < n) d = dp[i+1][j];
            dp[i][j] = (dp[i][j]%MOD+r%MOD+d%MOD)%MOD;
        }
    }
    println(dp[0][0]);
    return 0;
}

