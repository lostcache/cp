#include <algorithm>
#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    int tar_count = 0;
    int a[3] = {0};
    int res = 0;
    while (tar_count < 3) {
        for (int i = 0; i < 3 && tar_count < 3; ++i) {
            a[i] =
                std::min(a[(i + 1) % 3] * 2 + 1, n);
            if (a[i] == n)
                tar_count++;
            res++;
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
