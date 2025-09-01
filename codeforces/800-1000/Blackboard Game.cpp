#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    int a[4] = {0};
    for (int i = 0; i < n; ++i) {
        a[i % 4]++;
    }
    if (a[0] == a[3] && a[1] == a[2]) {
        std::cout << "Bob" << std::endl;
    } else {
        std::cout << "Alice" << std::endl;
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
