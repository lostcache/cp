#include <algorithm>
#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    int mx = 0, mxidx = -1;
    bool all_same = true;
    int ls;
    std::cin >> ls;
    if (ls > mx) {
        mxidx = 0;
        mx = ls;
    }
    for (int i = 1; i < n; ++i) {
        int t;
        std::cin >> t;
        if (t != ls) {
            all_same = false;
        }
        if (t > mx) {
            mx = t;
            mxidx = i;
        }
        ls = t;
    }
    if (all_same) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << (i != mxidx ? 1 : 2) << (i == n - 1 ? '\n' : ' ');
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
