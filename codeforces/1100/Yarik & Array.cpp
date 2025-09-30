#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vec vector
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)

typedef string str;

// const int inf = 1e19 + 7;
// const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve() {
    int n, _max, _global_max, _curr, _prev;
    cin >> n;
    cin >> _prev;
    _max = _prev;
    _global_max = _prev;
    FOR(i, 2, n) {
        cin >> _curr;
        if (abs(_prev % 2) != abs(_curr % 2)) {
            _max = max(_curr + _max, _curr);
        } else {
            _max = _curr;
        }
        _global_max = max(_global_max, _max);
        _prev = _curr;
    }
    cout << _global_max << endl;
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
