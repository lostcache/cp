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
    vl dp(n+1, inf); dp[n] = 0;
    FORD(i, n, -1) {
        if (dp[i] == inf) continue;
        ll temp = i;
        while (temp) {
            int d = temp % 10;
            if (i - d < 0) continue;
            dp[i - d] = min(dp[i - d], dp[i]+1);
            temp /= 10;
        }
    }
    println(dp[0]);
    return 0;
}

