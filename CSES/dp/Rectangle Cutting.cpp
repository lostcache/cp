#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>
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
#define pb push_back
#define FOR(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (ll i = (a); i >= (b); --i)
#define SORT(a) sort((a).begin(), (a).end())
#define println(a) (cout << (a) << endl)
#define print(a) (cout << (a))
#define REV(a) reverse((a).begin(), (a).end())
const int inf = 1e9;
const ll ll_inf = 1e18;
const ll MOD = 1e9 + 7;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const char cdirs[4] = {'R', 'L', 'D', 'U'};

using namespace std;

struct FastIO {
  FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} fastio_init;


int main() { 
    ll a, b; cin >> a >> b;
    vvl dp(a+1, vl(b+1, ll_inf));
    FOR(i, 1, a) {
        FOR(j, 1, b) {
            if (i == j) dp[i][j]=0;
            else {
                FOR(k, 1, i-1) dp[i][j]=min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
                FOR(l, 1, j-1) dp[i][j]=min(dp[i][j], 1+dp[i][l]+dp[i][j-l]);
            }
        }
    }
    println(dp[a][b]);
    return 0; 
}
