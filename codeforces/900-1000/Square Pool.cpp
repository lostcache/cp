#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define print(a) cout << (a) << ' ';
#define println(a) cout << (a) << '\n';
#define vec vector
typedef long long ll;

using namespace std;

const int inf = 1e9 + 7;
const ll ll_inf = 1e19 + 7;

void solve() {
    int n, s, res = 0;
    cin >> n >> s;
    FOR(i, 0, n - 1) {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        if ((x == y && dx == dy) || (x == abs(s - y) && -dx == dy)) {
            res++;
        }
    }
    println(res);
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
