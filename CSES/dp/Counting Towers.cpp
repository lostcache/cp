#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
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
    ll mx=1e6;
    vll a(mx+1), b(mx+1); a[1]=1; b[1]=1;
    FOR(i, 2, mx) {
        a[i]=(4*a[i-1]+b[i-1])%MOD;
        b[i]=(a[i-1]+2*b[i-1])%MOD;
    }
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        println((a[n]+b[n])%MOD);
    }
    return 0;
}

