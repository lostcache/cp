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
    ll n; ll x; cin >> n >> x;
    vec<pll> a(n);
    FOR (i, 0, n-1) { cin >> a[i].first; a[i].second = i + 1; }
    sort(a.begin(), a.end());
    FOR (i, 0, n-1) {
        ll l = i+1, r = n-1;
        while (l < r) {
            ll sum = a[i].first + a[l].first + a[r].first;
            if (sum == x) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << "\n";
                return 0;
            }
            sum < x ? l++ : r--;
        }
    }

    cout << "IMPOSSIBLE\n";
}

