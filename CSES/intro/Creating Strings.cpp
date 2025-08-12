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

vl used;
set<string> seen;
vec<string> res;
void dfs(string &s, string si, ll n) {
    if (si.size() == n && seen.find(si) == seen.end()) {
        res.pb(si);
        seen.insert(si);
        return;
    }

    FOR(i, 0, n-1) {
        if (used[i]) continue;
        used[i]=true;
        dfs(s, si+s[i], n);
        used[i] = false;
    }
}

int main() {
    string s; cin >> s; SORT(s);
    used.resize(s.size());
    dfs(s, "", s.size());
    println(res.size());
    for (auto s: res) println(s);
    return 0;
}

