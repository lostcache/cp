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
    ll n, x; cin >> n >> x;
    vl c(n, 0); FOR(i, 0, n) cin >> c[i];
    vl dp(x+1, 0); dp[0] = 1;
    FOR(j, 0, n) {
        FOR(i, 1, x+1) {
            if (i - c[j] < 0) continue;
            dp[i] = (dp[i] + dp[i-c[j]])%MOD;
        }
    }
    println(dp[x]);
    return 0;
}

