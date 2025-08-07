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
    vec<string> map(n); FOR(i, 0, n) cin >> map[i];
    vvl visited(n, vl(m, 0)) ;
    vec<vec<tuple<ll, ll, char>>> paren(n, vec<tuple<ll, ll, char>>(m, {-1, -1, 'N'}));
    ll start_i, start_j;
    FOR(i, 0, n-1) {
        FOR(j, 0, m-1) {
            if (map[i][j] != 'A') continue;
            queue<pll> q;
            q.push({i, j}); visited[i][j]=1; paren[i][j]={-1, -1, 'N'};
            start_i = i; start_j = j;
            while(!q.empty()) {
                const auto [ci, cj] = q.front(); q.pop();
                if (map[ci][cj]=='B') {
                    ll cci=ci, ccj=cj;
                    string ans = "";
                    while (true) {
                        if (cci==start_i&&ccj==start_j) break;
                        auto [pi, pj, cdir] = paren[cci][ccj];
                        ans+=cdir;
                        cci=pi; ccj=pj;
                    }
                    println("YES"); println(ans.size()); reverse(ans.begin(), ans.end()); println(ans);
                    return 0;
                }
                FOR(d, 0, 3) {
                    ll ni = ci+dirs[d][0], nj=cj+dirs[d][1];
                    if (ni>=0&&ni<n && nj>=0&&nj<m && !visited[ni][nj] && map[ni][nj]!='#') {
                        q.push({ni, nj}); visited[ni][nj]=1; paren[ni][nj]={ci, cj, cdirs[d]};
                    }
                }
            }
        }
    }
    println("NO");
    return 0;
}

