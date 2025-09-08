#include <algorithm>
#include <iostream>

void solve() {
    int n, k;
    std::cin >> n >> k;
    int res = 0;
    if (k % 2 == 1) {
        n -= std::min(n, k);
        res++;
        k--;
    }
    if (n == 0) {
        std::cout << res << std::endl;
        return;
    }
    res += n / k;
    if (n % k > 0) {
        res++;
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
