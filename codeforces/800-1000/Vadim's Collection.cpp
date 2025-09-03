#include <algorithm>
#include <iostream>
#include <string>

int a[10];

void solve() {
    std::fill_n(a, 10, 0);
    std::string s, res;
    res.reserve(10);
    std::cin >> s;
    for (int i = 0; i < 10; ++i) {
        a[s[i] - '0']++;
    }
    for (int i = 1; i <= 10; ++i) {
        bool found = false;
        for (int j = (10 - i); j <= 9; ++j) {
            if (a[j] != 0) {
                res.push_back(j + '0');
                a[j]--;
                found = true;
                break;
            }
        }

        for (int j = (10 - i + 1); j <= 9 && !found; ++j) {
            if (a[j] != 0) {
                res.push_back(j + '0');
                a[j]--;
                break;
            }
        }
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
