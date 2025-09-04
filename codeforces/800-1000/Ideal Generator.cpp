#include <iostream>


void solve() {
    int k;
    std::cin >> k;
    if (k % 2 == 0) {
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
