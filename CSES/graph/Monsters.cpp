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


int main() {
    int n, m; cin >> n >> m;
    vec<string> map(n);
    FOR(i, 0, n-1) cin >> map[i];

    queue<pll> mq;
    queue<tuple<ll, ll, ll>> pq;

    vvl md(n, vl(m, inf)); vvl pd(n, vl(m, inf));
    vec<vec<int>> parent_dir(n, vec<int>(m, -1));

    ll start_i = -1, start_j = -1;
    FOR(i, 0, n-1) {
        FOR(j, 0, m-1) {
            if (map[i][j] == 'M') {
                md[i][j] = 0;
                mq.push({i, j});
            }
            if (map[i][j] == 'A') {
                start_i = i;
                start_j = j;
            }
        }
    }

    while (!mq.empty()) {
        auto [mi, mj] = mq.front(); mq.pop();
        for (int d = 0; d < 4; d++) {
            ll ni = mi + dirs[d][0], nj = mj + dirs[d][1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if (map[ni][nj] != '#' && md[ni][nj] > md[mi][mj] + 1) {
                    md[ni][nj] = md[mi][mj] + 1;
                    mq.push({ni, nj});
                }
            }
        }
    }

    pd[start_i][start_j] = 0;
    pq.push({start_i, start_j, 0});
    pll escape_pos = {-1, -1};
    while (!pq.empty()) {
        auto [ci, cj, cd] = pq.front(); pq.pop();
        if (ci == 0 || cj == 0 || ci == n-1 || cj == m-1) {
            escape_pos = {ci, cj};
            break;
        }
        for (int d = 0; d < 4; d++) {
            ll ni = ci + dirs[d][0], nj = cj + dirs[d][1];
            ll nd = cd + 1;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if (map[ni][nj] != '#' && pd[ni][nj] > nd && nd < md[ni][nj]) {
                    pd[ni][nj] = nd; pq.push({ni, nj, nd}); parent_dir[ni][nj] = d;
                }
            }
        }
    }

    if (escape_pos.first == -1) {
        cout << "NO\n";
        return 0;
    }

    string path;
    ll x = escape_pos.first, y = escape_pos.second;
    while (x != start_i || y != start_j) {
        int d = parent_dir[x][y];
        path.pb(cdirs[d]);
        x -= dirs[d][0];
        y -= dirs[d][1];
    }
    REV(path);
    cout << "YES\n" << path.size() << "\n" << path << "\n";
    return 0;
}

