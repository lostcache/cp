#include <iostream>
#include <string>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string res = "";
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
        char ni = (i < k ? '1' : '0');
        res.push_back(ni);
    }
    std::cout << res << std::endl;
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
