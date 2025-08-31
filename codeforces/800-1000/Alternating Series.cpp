#include <iostream>

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      std::cout << -1;
    } else {
      std::cout << (i == n - 1 ? 2 : 3);
    }
    std::cout << (i == n - 1 ? '\n' : ' ');
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
