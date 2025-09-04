#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    std::cout << 2 * n << std::endl;
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
