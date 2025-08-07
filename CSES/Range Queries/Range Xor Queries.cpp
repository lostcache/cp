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

vl a, t;

void build_tree(ll l, ll r, ll ti) {
    if (l == r) t[ti] = a[l];
    else {
        ll m = (l+r)/2;
        build_tree(l, m, ti*2); build_tree(m+1, r, ti*2+1);
        t[ti] = t[ti*2] ^ t[ti*2+1];
    }
}

ll query_tree(ll l, ll r, ll ql, ll qr, ll ti) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && qr >= r) return t[ti];
    ll m = (l+r)/2;
    return query_tree(l, m, ql, qr, ti*2) ^ query_tree(m+1, r, ql, qr, ti*2+1);
}

void update_tree(ll l, ll r, ll ti, ll ui, ll v) {
    if (l == r) t[ti] = v;
    else {
        ll m = (l+r)/2;
        if (ui <= m) update_tree(l, m, ti*2, ui, v);
        else update_tree(m+1, r, ti*2+1, ui, v);
        t[ti] = t[ti*2] ^ t[ti*2+1];
    }
}

int main() {
    ll n, q; cin >> n >> q;
    a.resize(n+1); t.resize(4*(n+1)); FOR(i, 1, n) cin >> a[i];
    build_tree(1, n, 1);
    while (q--) {
        ll l, r; cin >> l >> r;
        println(query_tree(1, n, l, r, 1));
    }
    return 0;
}
