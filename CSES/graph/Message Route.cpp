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
#define SORT(a) sort((a).begin(), (a).end());
#define println(a) cout << (a) << endl;
#define print(a) cout << (a);

const ll MOD = 1e9+7;
const int inf = 1e9;
const ll ll_inf = 1e18;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const char cdirs[4] = {'R', 'L', 'D', 'U'};

using namespace std;

int main() {
    ll n, m; cin >> n >> m;
    vvl adj(n+1, vl ());
    FOR(i, 1, m) { ll t, f; cin >> t >> f; adj[t].push_back(f); adj[f].push_back(t); }

    vl visited(n+1, 0);
    vl paren(n+1, -1);
    queue<ll> q;
    q.push(1); visited[1]=1;
    while (!q.empty()) {
        ll ci = q.front(); q.pop();
        if (ci == n) {
            vl path;
            ll c=ci;
            path.push_back(c);
            while (paren[c]!=-1) {
                path.push_back(paren[c]);
                c=paren[c];
            }
            println(path.size());
            FORD(i, path.size()-1, 0) {
                print(path[i]);
                if (i) { print(" "); }
                else { print("\n"); }
            }
            return 0;
        }
        for (auto ni: adj[ci]) {
            if (visited[ni]) continue;
            q.push(ni); visited[ni]=1; paren[ni]=ci;
        }
    }

    println("IMPOSSIBLE");
    return 0;
}

