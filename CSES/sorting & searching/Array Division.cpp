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

vll a;
bool can_divide(ll lt, ll k) {
    ll sa=1, cs=0;
    for (auto ai: a) {
        if (cs+ai<=lt) { cs+=ai; }
        else { sa+= 1; cs=ai; }
    }
    return sa<=k;
}

int main() {
    ll n, k; cin >> n >> k; a.resize(n); FOR(i, 0, n-1) cin >> a[i];
    ll l=*max_element(a.begin(), a.end()), r=accumulate(a.begin(), a.end(), 0LL);
    ll res=r;
    while (l <= r) {
        ll m=(l+r)/2;
        if (can_divide(m, k)) { res = m; r = m-1; }
        else { l=m+1; }
    }
    println(res);
    return 0;
}

