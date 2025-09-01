#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    long long n, c;
    cin >> n >> c;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int l = 0, r = n;

    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] <= c) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    int pos = l - 1;

    if (pos < 0) {
        cout << n << endl;
        return;
    }

    long long mul = 1;
    int saved = 0;

    for (int i = pos; i >= 0; i--) {
        if (a[i] * mul <= c) {
            mul *= 2;
            saved++;
        }
    }

    cout << n - saved << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
