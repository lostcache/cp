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
#define vll vector<ll>
#define vvl vector<vl>
#define pb push_back
#define FOR(i, a, b) for(ll i=(a); i<=(b); ++i)
#define FORD(i, a, b) for(ll i=(a); i>=(b); --i)
#define SORT(a) sort((a).begin(), (a).end())
#define println(a) (cout << (a) << endl)
#define print(a) (cout << (a))
#define REV(a) reverse((a).begin(), (a).end())

const int inf = 1e9;
const ll ll_inf = 1e18;
const ll MOD = 1e9+7;
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
    ll n, x; cin >> n >> x;
    vll a(n); FOR(i, 0, n-1) cin >> a[i];
    map<ll, vec<pll>> cache;
    FOR(i, 0, n-1) {
        FOR(j, i+1, n-1) {
            ll cs=a[i]+a[j]; ll xi=x-cs;
            if (cache.find(xi) != cache.end()) {
                for (auto [p, q]: cache[xi]) {
                    if (p!=i&&p!=j&&q!=i&&q!=j) {
                        cout << p+1 << " " << q+1 << " " << i+1 << " " << j+1 << endl;
                        return 0;
                    }
                }
            }
            cache[cs].pb({i, j});
        }
    }

    println("IMPOSSIBLE");
    return 0;
}

