#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

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
#define SORT(a) sort((a).begin(), (a).end())
#define println(a) (cout << (a) << endl)
#define print(a) (cout << (a))
#define REV(a) reverse((a).begin(), (a).end())

const ll MOD = 1e9+7;
const int inf = 1e9;
const ll ll_inf = 1e18;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const char cdirs[4] = {'R', 'L', 'D', 'U'};

using namespace std;

vvl adj;
vvl dp(2);

void dfs(ll p, ll c) {
    dp[0][c] = 0;
    dp[1][c] = 0;
    ll base = 0;
    ll best = 0;

    for (auto cc: adj[c]) {
        if (cc == p) continue;
        dfs(c, cc);

        dp[1][c] += dp[0][cc];

        base += dp[0][cc];

        ll gain = 1 + dp[1][cc] - dp[0][cc];
        best = max(gain, best);
    }

    dp[0][c] = base + best;
}

int main() {
    ll n; cin >> n; adj.resize(n+1); dp[0].resize(n+1); dp[1].resize(n+1);
    FOR(i, 1, n-1) { ll a, b; cin >> a >> b; adj[a].pb(b); adj[b].pb(a); }
    dfs(-1, 1);
    println(max(dp[0][1], dp[1][1]));
    return 0;
}

