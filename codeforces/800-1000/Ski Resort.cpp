#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

const int inf = 1e9;
const ll inf_ll = 1e17;

void solve() {
    int n, k, q, res = 0;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (auto &ai: a) {
        cin >> ai;
    }
    int win_len = 0;
    for (auto &ai: a) {
        if (ai <= q) {
            win_len++;
        } else {
            if (win_len >= k) {
                res += (win_len - k + 1) * (win_len - k + 2) / 2;
            }
            win_len = 0;
        }
    }
    if (win_len >= k) {
        res += (win_len - k + 1) * (win_len - k + 2) / 2;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) { solve(); }
    return 0;
}
