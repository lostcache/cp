#include <algorithm>
#include <iostream>

void solve() {
    int a, b;
    long long x, y;
    std::cin >> a >> b >> x >> y;
    if (b > a) {
        long long cost = 0;
        while (a < b) {
            if (a % 2 == 0) {
                cost += std::min(x, y);
            } else {
                cost += x;
            }
            a++;
        }
        std::cout << cost << std::endl;
    } else if (a > b) {
        if (a % 2 == 0) {
            std::cout << -1 << std::endl;
        } else {
            if (a - b > 1) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << y << std::endl;
            }
        }
    } else {
        std::cout << 0 << std::endl;
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
