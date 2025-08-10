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
vl subs;

ll dfs(ll node) {
    ll cnt = 0;
    for (auto ch: adj[node]) {
        cnt += 1 + dfs(ch);
    }
    subs[node]=cnt;
    return cnt;
}

int main() {
    ll n; cin >> n;
    subs.resize(n+1, 0);
    adj.resize(n+1); FOR(i, 2, n) {ll b; cin >> b; adj[b].pb(i); }
    dfs(1);
    FOR(i, 1, n) {
        print(subs[i]);
        if (i==n) print("\n");
        else print(" ");
    }
    return 0;
}

