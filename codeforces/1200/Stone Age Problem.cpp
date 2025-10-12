#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e15 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int currSum = 0;
    for (auto& ai : a) {
        cin >> ai;
        currSum += ai;
    }
    vector<int> last1queryIdx(n, -1);
    vector<int> last1queryVal(n, -1);
    for (int i = 0; i < n; ++i) {
        last1queryVal[i] = a[i];
    }
    int last2QueryIdx = -1;
    int last2QueryVal = -1;
    for (int qi = 0; qi < q; ++qi) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, x, old_val;
            cin >> idx >> x;
            idx--;

            if (last2QueryIdx > last1queryIdx[idx]) {
                old_val = last2QueryVal;
            } else {
                old_val = last1queryVal[idx];
            }

            currSum = currSum - old_val + x;
            last1queryIdx[idx] = qi;
            last1queryVal[idx] = x;
        } else if (type == 2) {
            cin >> last2QueryVal;
            currSum = n * last2QueryVal;
            last2QueryIdx = qi;
        }
        cout << currSum << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}

    return 0;
}
