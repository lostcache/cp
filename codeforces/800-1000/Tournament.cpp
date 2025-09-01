#include <algorithm>
#include <iostream>

void solve() {
    int n, j, k;
    std::cin >> n >> j >> k;
    int val;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 1 == j) {
            std::cin >> val;
        } else {
            int temp;
            std::cin >> temp;
            mx = std::max(mx, temp);
        }
    }
    if (k == 1 && val < mx) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
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
