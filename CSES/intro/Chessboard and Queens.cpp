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

ll res = 0;
vvl vst(8, vl (8, 0));
vec<string> b(8);

bool atk(ll i, ll j) {
    FOR(ii, 0, 7) { if (vst[ii][j]) { return true; } }
    FOR(jj, 0, 7) { if (vst[i][jj]) { return true; } }
    for (int ii = 1; ii+i<=7 && ii+j<=7; ii++) {
        if (vst[i+ii][j+ii]) return true;
    }
    for (int ii = 1; i-ii>=0 && j-ii>=0; ii++) {
        if (vst[i-ii][j-ii]) return true;
    }
    for (int ii = 1; i+ii <= 7 && j-ii >= 0; ii++) {
        if (vst[i+ii][j-ii]) return true;
    }
    for (int ii = 1; i-ii >= 0 && j+ii <= 7; ii++) {
        if (vst[i-ii][j+ii]) return true;
    }
    return false;
}

void dfs(ll i) {
    if (i == 8) { res++; return; }

    FOR(j, 0, 7) {
        if (atk(i, j) || b[i][j]=='*' || vst[i][j]) continue;
        vst[i][j]=true;
        dfs(i+1);
        vst[i][j]=false;
    }
}

int main() {
    FOR(i, 0, 7) cin >> b[i];
    dfs(0);
    println(res);
    return 0;
}

