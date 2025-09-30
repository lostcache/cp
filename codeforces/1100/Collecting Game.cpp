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
    int n, _sum = 0;
    cin >> n;
    vec<int> a(n), pre_sum(n, 0), a_srt;
    map<int, int> ele_ans;
    FOR(i, 0, n - 1) { cin >> a[i]; }
    a_srt = a;
    sort(a_srt.begin(), a_srt.end());
    FOR(i, 0, n - 1) {
        _sum += a_srt[i];
        pre_sum[i] = _sum;
    }
    int r_incl = 0;
    FORD(i, n - 1, 0) {
        int _curr_right_incl = 0;
        if (i + 1 <= n - 1 && pre_sum[i] >= a_srt[i + 1]) {
            _curr_right_incl = r_incl + 1;
        }
        ele_ans[a_srt[i]] = i + _curr_right_incl;
        r_incl = _curr_right_incl;
    }
    FOR(i, 0, n - 1) { cout << ele_ans[a[i]] << ' '; }
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
