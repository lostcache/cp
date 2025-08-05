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
#define FOR(i, a, b) for(ll i=(a); i<=(b); ++i)
#define FORD(i, a, b) for(ll i=(a); i>=(b); --i)
#define SORT(a) sort((a).begin(), (a).end());
#define println(a) cout << (a) << endl;
#define print(a) cout << (a);

const ll MOD = 1e9+7;
const int inf = 1e9;
const ll ll_inf = 1e18;

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vl x(n+1);
    FOR(i, 1, n) cin >> x[i];
    vvl dp(n+1, vl (m+1, 0));
    FOR(i, 1, m) {
        if (x[1] == 0 || x[1] == i) dp[1][i] = 1;
    }

    FOR(i, 2, n) {
        FOR(j, 1, m) {
            if (x[i] == 0 || x[i] == j) {
                dp[i][j] = 0;
                FOR(d, -1, 1) {
                    if (j+d>=1 && j+d<=m) {
                        dp[i][j] = (dp[i][j]+dp[i-1][j+d])%MOD;
                    }
                }
            }
        }
    }
    ll ans = 0;
    FOR(i, 1, m) {
        ans=(ans + dp[n][i])%MOD;
    }
    println(ans);
    return 0;
}

