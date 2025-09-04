#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (auto &ai : a) {
        std::cin >> ai;
    }
    std::sort(a.begin(), a.end(), std::greater<>());
    int res = 0;
    int l = 0, r = 0, mn = 1e9;
    while (r < n && l < n) {
        mn = std::min(a[r], mn);
        if ((r - l + 1) * mn >= x || a[r] >= x) {
            res += 1;
            mn = 1e9;
            l = r + 1;
        }
        r++;
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
