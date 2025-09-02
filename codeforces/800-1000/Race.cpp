#include <algorithm>
#include <iostream>

void solve() {
    int a, x, y;
    std::cin >> a >> x >> y;
    if (x > y) {
        std::swap(x, y);
    }
    if (a < x || a > y) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    std::cout << std::endl;
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
