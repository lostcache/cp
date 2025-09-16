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
#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
#define FORD(i, a, b) for (ll i = a; i >= b; --i)
#define MOD(a, b) (a) % (b)
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define println(a) (cout << (a) << '\n')
#define vec vector
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define m_p make_pair

using namespace std;

const int inf = 1e9;
const ll inf_ll = 1e17;

void solve() {
    ll n; cin >> n;
    vl a(n); FOR(i, 0, n -1) cin >> a[i];
    if (n < 3) { println("NO"); return; }
    vpl minLeft(n, {-1, -1});
    vpl minRight(n, {-1, -1});
    pl ml = m_p(a[0], 0);
    FOR(i, 1, n - 1) {
        minLeft[i] = ml;
        if (a[i] < ml.first) { ml = m_p(a[i], i); }
    }
    pl mr = m_p(a[n - 1], n - 1);
    FORD(i, n-2, 0) {
        minRight[i] = mr;
        if (a[i] < mr.first) { mr = m_p(a[i], i); }
    }
    FOR(i, 1, n - 2) {
        if (minLeft[i].first < a[i] && a[i] > minRight[i].first) {
            println("YES");
            cout << minLeft[i].second+1 << ' ' << i + 1 << ' ' << minRight[i].second+1 << endl;
            return;
        }
    }
    println("NO");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) { solve(); }
    return 0;
}
