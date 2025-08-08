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
vl md;

tuple<ll, ll, ll> bfs(ll node) {
    tuple<ll, ll, ll> res = {-1, node, 0};
    queue<tuple<ll, ll, ll>> q; q.push(res);
    while (!q.empty()) {
        auto [p, c, d] = q.front(); q.pop();
        res = {p, c, d};
        for (auto n: adj[c]) {
            if (n == p) continue;
            q.push({c, n, d+1});
        }
    }

    return res;
}

int main() {
    ll n; cin >> n;
    if (n == 1) { println(0); return 0; }
    adj.resize(n+1); md.resize(n+1);
    FOR(i, 1, n) { ll a, b; cin >> a >> b; adj[a].pb(b); adj[b].pb(a); }
    auto [p1, e1, d1] = bfs(1);
    auto [p2, e2, d2] = bfs(e1);
    println(d2);
    return 0;
}

