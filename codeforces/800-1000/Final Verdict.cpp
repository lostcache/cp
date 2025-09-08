#include <iostream>

void solve() {
    int n, x;
    std::cin >> n >> x;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        sum += t;
    }
    std::cout << ((float)sum / (float)n == (float)x ? "YES" : "NO")
              << std::endl;
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
