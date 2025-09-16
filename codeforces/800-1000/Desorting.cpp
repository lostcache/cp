#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    int prev;
    int curr;
    std::cin >> prev;
    int min_diff = 1e9;
    for (int i = 1; i < n; ++i) {
        std::cin >> curr;
        min_diff = std::min(min_diff, curr - prev);
        prev = curr;
    }
    if (min_diff < 0) {
        std::cout << 0 << std::endl;
        return;
    }
    std::cout << min_diff / 2 + 1 << std::endl;
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
