#include <algorithm>
#include <iostream>
#include <string>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s, rs;
    std::cin >> s;
    rs = s;
    std::reverse(rs.begin(), rs.end());
    if (s < rs || (k > 0 && *min_element(s.begin(), s.end()) !=
                                *max_element(s.begin(), s.end()))) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return;
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
