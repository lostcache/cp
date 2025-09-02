#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    for (int a = 0; a <= 100; a++) {
        for (int b = 0; b <= 100; b++) {
            if (a * a + b * b + 2 * a * b == n) {
                std::cout << a << ' ' << b << std::endl;
                return;
            }
        }
    }

    std::cout << -1 << std::endl;
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
