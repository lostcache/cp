#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    cout << 0 << "\n";
    for (int i = 2; i <= n; ++i) {
        ll total = 1LL * i * i * (i * i - 1) / 2;
        ll attacking = 0;
        if (i > 2) {
            attacking = 4LL * (i - 1) * (i - 2);
        }
        cout << total - attacking << "\n";
    }
    return 0;
}

