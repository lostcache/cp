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

void build_tree(vl &a, vl &t, ll l, ll r, ll ti) {
    if (l == r) t[ti] = a[l];
    else {
        ll m = (l+r)/2;
        build_tree(a, t, l, m, ti*2);
        build_tree(a, t, m+1, r, ti*2+1);
        t[ti] = min(t[ti*2], t[ti*2+1]);
    }
}

ll query_tree(vl &t, ll l, ll r, ll ql, ll qr, ll ti) {
    if (qr < l || ql > r) return ll_inf;
    if (ql <= l && qr >= r) return t[ti];
    else {
        ll m = (l+r)/2;
        return min(query_tree(t, l, m, ql, qr, ti*2),
                   query_tree(t, m+1, r, ql, qr, ti*2+1));
    }
}


void update_tree(vl &t, vl &a, ll l, ll r, ll ti, ll ui, ll v) {
    if (l == r) { a[l] = v; t[ti] = v; }
    else {
        ll m = (l+r)/2;
        if (ui <= m) update_tree(t, a, l, m, ti*2, ui, v);
        else update_tree(t, a, m+1, r, ti*2+1, ui, v);
        t[ti] = min(t[ti*2], t[ti*2+1]);
    }
}

int main() {
    ll n, q; cin >> n >> q;
    vl a(n+1), t(4*(n+1)); FOR(i, 1, n) cin >> a[i];
    build_tree(a, t, 1, n, 1);
    while (q--) {
        ll op, x, y; cin >> op >> x >> y;
        if (op == 1) update_tree(t, a, 1, n, 1, x, y);
        else if (op == 2) println(query_tree(t, 1, n, x, y, 1));
    }
    return 0;
}

