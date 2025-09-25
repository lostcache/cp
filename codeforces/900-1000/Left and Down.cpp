#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define vec vector
typedef long long ll;

using namespace std;

const int inf = 1e9 + 7;
const ll ll_inf = 1e19 + 7;

ll gcd(ll a, ll b) {
    while (b) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll _gcd = gcd(a, b);
    if (a / _gcd <= k && b / _gcd <= k) {
        cout << 1;
    } else {
        cout << 2;
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
