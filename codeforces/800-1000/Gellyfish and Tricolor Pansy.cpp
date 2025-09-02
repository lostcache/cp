#include <iostream>
#include <algorithm>

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int ma = std::min(a, c);
    int mb = std::min(b, d);
    if (ma > mb) {
        std::cout << "Gellyfish";
    } else if (ma < mb) {
        std::cout << "Flower";
    } else {
        std::cout << "Gellyfish";
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
