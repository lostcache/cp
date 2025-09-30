#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vec vector
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)

typedef string str;

const int inf = 1e19 + 7;
// const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve() {
    int n, _min = inf, _max = -inf, res = -inf, sum = 0;
    cin >> n;
    vec<int> a(n);
    vec<int> preSum(n, -1);
    FOR(i, 0, n - 1) {
        cin >> a[i];
        _min = min(_min, a[i]);
        _max = max(_max, a[i]);
        sum += a[i];
        preSum[i] = sum;
    }
    res = max(res, _max - _min);
    FOR(k, 2, n / 2) {
        if (n % k == 0) {
            int win_len = n / k, l = 0, r = l + win_len - 1, wMin = inf,
                wMax = -inf;
            while (r < n) {
                int exSum = l - 1 > 0 ? preSum[l - 1] : 0, currSum = preSum[r],
                    win_abs_sum = abs(currSum - exSum);
                wMin = min(wMin, win_abs_sum), wMax = max(wMax, win_abs_sum);
                l += win_len, r += win_len;
            }
            res = max(res, wMax - wMin);
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
