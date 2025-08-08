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
vl dist1;
vl dist2;

tuple<ll, ll, ll> bfs(ll node, vl &dist) {
    tuple<ll, ll, ll> far = {-1, node, 0}; 
    queue<tuple<ll, ll, ll>> q;
    q.push(far);

    while (!q.empty()) {
        auto [p, curr, d] = q.front(); q.pop();
        far = {p, curr, d};
        dist[curr] = max(d, dist[curr]);
        for (auto nei: adj[curr]) {
            if (nei == p) continue;
            q.push({curr, nei, d+1});
        }
    }
    dist[get<1>(far)] = max(get<2>(far), dist[get<1>(far)]);
    return far;
}

int main() {
    ll n; cin >> n; adj.resize(n+1); dist1.resize(n+1); dist2.resize(n+1);
    FOR(i, 1, n-1) { ll a, b; cin >> a >> b; adj[a].pb(b); adj[b].pb(a); }
    auto [lol, n1, d] = bfs(1, dist1); // get one end of diameter
    auto [hehe, n2, d1] = bfs(n1, dist2); // dist from one end of diameter
    auto [hehe1, n3, d2] = bfs(n2, dist2); // dist from other end of diameter
    FOR(i, 1, n) {
        print(max(dist1[i], dist2[i]));
        if (i == n) print("\n");
        else print(" ");
    }
    return 0;
}

