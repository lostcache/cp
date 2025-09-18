#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define ll long long
#define str string
#define vec vector
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vl vec<ll>
#define vi vec<int>
#define vpi vec<pi>
#define vpl vec<pl>
#define vvi vec<vi>
#define vvl vec<vl>

#define m_p make_pair
#define f first
#define s second
#define p_b push_back

#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
#define FORD(i, a, b) for (ll i = a; i >= b; --i)
#define MOD(a, b) (a) % (b)
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define println(a) (cout << (a) << '\n')

using namespace std;

const int inf = 1e9;
const ll inf_ll = 1e17;

void solve() {
    ll n, k, t; cin >> n >> k;
    vl a(n); FOR(i, 0, n - 1) cin >> a[i];
    if (k == 4) {
        ll even_cnt = 0;
        bool any_mod_3 = false;
        FOR(i, 0, n - 1) {
            if (a[i] % 4 == 0) { println(0); return; }
            if (a[i] % 2 == 0) even_cnt++;
            if (a[i] % 4 == 3) any_mod_3 = true;
        }
        if (even_cnt >= 2) { println(0); }
        else if (any_mod_3) { println(1); }
        else if (even_cnt == 1) { if (n == 1) println(2); else println(1); }
        else { println(2); }
    } else {
        ll min_mod = inf_ll;
        FOR(i, 0, n - 1) {
            min_mod = min(min_mod, a[i] % k != 0 ? k - (a[i] % k) : 0);
        }
        println(min_mod);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) { solve(); }
    return 0;
}
