#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define vi vector<int>
#define vvi vector<vi>

const int inf = 1e15 + 7;
int n;
string s;

int check(int l, int r, char c) {
  int cost = 0;
  while (l < r) {
    while (l < r && s[l] != s[r]) {
      if (s[l] == c) {
        while (l < r && s[l] == c && s[l] != s[r]) {
          cost++, l++;
        }
      } else if (s[r] == c) {
        while (l < r && s[r] == c && s[l] != s[r]) {
          cost++, r--;
        }
      } else {
        return inf;
      }
    }
    l++, r--;
  }
  return cost;
}

void solve() {
  cin >> n;
  cin >> s;
  int l = 0, r = n - 1;
  while (l < r) {
    if (s[l] != s[r]) {
      int lc = check(l, r, s[l]), rc = check(l, r, s[r]);
      int ans = min(lc, rc);
      cout << (ans >= inf ? -1 : ans) << endl;
      return;
    }
    l++, r--;
  }
  cout << 0 << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
