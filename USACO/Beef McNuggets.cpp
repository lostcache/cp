/*
ID: harshde2
LANG: C++
TASK: nuggets
*/

#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <unordered_set>
#include <climits>
#include <tuple>
#include <unordered_map>

using namespace std;

#define vec vector
#define ll long long

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b); i >= a; i--)
#define F0Rd(i,a) for (int i = (a); i >= 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())

#define INF 1e9
#define LL_INF 45e17
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define pA first
#define pB second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define ll long long
#define MOD (int)(2e+9+11)
#define SET(vec, val, size) for (int i = 0; i < size; i++) vec[i] = val;
#define SET2D(arr, val, dim1, dim2) F0R(i, dim1) F0R(j, dim2) arr[i][j] = val;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;

int N;
int ni[10];
int dp[256*256+100];

int gcd(int a, int b) {
  while (b) {
    int temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

int main() {
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);

    memset(ni, 0, sizeof(ni));
    memset(dp, 0, sizeof(dp));

    cin >> N;
    int maxSize = 0;
    FOR(i, 0, N) { 
      cin >> ni[i];
      maxSize = max(maxSize, ni[i]);
      if (ni[i] == 1) {
        cout << 0 << endl;
        return 0;
      }
    }

    int all_gcd = ni[0];
    FOR(i, 1, N) {
      all_gcd = gcd(all_gcd, ni[i]);
    }
    if (all_gcd != 1) {
      cout << 0 << endl;
      return 0;
    }

    dp[0] = 1;
    FOR(i, 0, 256*256+1) {
      if (!dp[i]) continue;

      FOR(j, 0, N) {
        if (i+ni[j] < 256*256+1)
          dp[i + ni[j]] = 1;
      }
    }

    int conse = 0;
    FOR(i, 1, 256*256+1) {
      if (dp[i]) {
        conse++;

        if (conse == maxSize) {
          cout << i-maxSize<<endl;
          return 0;
        }
      } else {
        conse = 0;
      }
    }

    cout << "0\n";
    return 0;
}

