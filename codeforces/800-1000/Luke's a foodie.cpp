#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), low(n), high(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (int i = 0; i < n; ++i) {
        low[i] = a[i] - x;
        high[i] = a[i] + x;
    }
    int res = 0;
    int gl = low[0], gh = high[0];
    for (int i = 1; i < n; ++i) {
        if (high[i] < gl || low[i] > gh) {
            res++;
            gl = low[i];
            gh = high[i];
        } else {
            gl = max(gl, low[i]);
            gh = min(gh, high[i]);
        }
    }
    cout << res << endl;
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
