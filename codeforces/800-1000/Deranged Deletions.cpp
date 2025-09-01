#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }

    int ls = a[0];
    bool already_sorted = true;
    for (int i = 1; i < n && already_sorted; ++i) {
        if (a[i] < ls) {
            std::cout << "YES" << std::endl;
            std::cout << 2 << std::endl;
            std::cout << ls << ' ' << a[i] << std::endl;
            return;
        }
        ls = a[i];
    }

    std::cout << "NO" << std::endl;
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
