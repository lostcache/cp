#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    int n1 = -1, n2 = -1, n1f = 0, n2f = 0;
    for (auto &ai : a) {
        if (n1 == -1) {
            n1 = ai;
            continue;
        }
        if (ai != n1 && n2 == -1) {
            n2 = ai;
            continue;
        }
        if (ai != n1 && ai != n2) {
            std::cout << "NO" << std::endl;
            return;
        } else if (ai == n1) {
            n1f++;
        } else if (ai == n2) {
            n2f++;
        }
    }
    if (n2 == -1) {
        std::cout << "YES" << std::endl;
        return;
    }
    if (n % 2 == 0) {
        std::cout << (n1f == n2f ? "YES" : "NO");
    } else {
        std::cout << (std::abs(n1f - n2f) == 1 ? "YES" : "NO");
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
