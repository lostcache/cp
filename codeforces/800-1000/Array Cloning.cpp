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

#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define str string
#define SORT(a) sort((a).begin(), (a).end())
#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
#define FORD(i, a, b) for (ll i = a; i >= b; --i)
#define println(a) cout << (a) << '\n';
#define MOD(a, b) (a) % (b)
#define MOD2(a) (a) % 2
#define ALL(a) (a.begin(), a.end())

const int inf = 1e9;
const ll inf_ll = 1e17;

using namespace std;

void solve() {
    int n; cin >> n;
    vi a(n);
    FOR(i, 0, n - 1) cin >> a[i];
    map<int, int> cnt;
    FOR(i, 0, n - 1) cnt[a[i]]++;
    int mx = 0;
    for (auto &[ele, fre]: cnt) { mx = max(mx, fre); }
    int rem = n - mx, res = 0;
    while (rem > 0) {
        res += min(mx, rem) + 1;
        rem -= mx;
        mx *= 2;
    }
    println(res);
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) { solve(); }
    return 0;
}
