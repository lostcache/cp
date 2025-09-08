#include <cmath>
#include <iostream>
#include <string>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if (n < 3) {
        std::cout << 0 << std::endl;
        return;
    }
    long long mc = 0, uc = 0;
    for (auto &c : s) {
        if (c == '-')
            mc++;
        else
            uc++;
    }
    if (mc < 2 || uc < 1) {
        std::cout << 0 << std::endl;
        return;
    }
    std::cout << (mc / 2) * ((mc + 1) / 2) * uc << std::endl;
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
