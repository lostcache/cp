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
    vvl adj(n+1, vl());
    FOR(i, 1, m) { ll f, t; cin >> f >> t; adj[f].push_back(t); adj[t].push_back(f); }
    vl visited(n+1, 0);
    vec<ll> repr;
    FOR(i, 1, n) {
        if (visited[i]) continue;
        queue<ll> q;
        q.push(i); visited[i]=1;
        while (!q.empty()) {
            ll c = q.front(); q.pop();
            for (auto &j : adj[c]) {
                if (!visited[j]) {
                    q.push(j); visited[j]=1;
                }
            }
        }
        repr.push_back(i);
    }

    if (repr.size() == 1) {
        println(0);
        return 0;
    }

    println(repr.size()-1);
    FOR(i, 0, repr.size()-2) {
        print(repr[i]); print(" "); println(repr[i+1]);
    }
    return 0;
}

