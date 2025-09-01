#include <iostream>

void solve() {
    int n, m;
    std::cin >> n >> m;
    if (n == 1 || m == 1) {
        std::cout << "NO";
    } else if (n == 2 && m == 2) {
        std::cout << "NO";
    } else {
        std::cout << "YES";
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
