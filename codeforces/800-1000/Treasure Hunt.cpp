#include <iostream>

void solve() {
    int x, y, a;
    std::cin >> x >> y >> a;
    std::cout << ((a % (x + y)) - x < 0 ? "NO" : "YES") << std::endl;
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
