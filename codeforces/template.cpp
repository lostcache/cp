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
#define str string
#define vec vector
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vl vec<ll>
#define vi vec<int>
#define vpi vec<pi>
#define vpl vec<pl>
#define vvi vec<vi>
#define vvl vec<vl>

#define m_p make_pair
#define f first
#define s second
#define p_b push_back

#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
#define FORD(i, a, b) for (ll i = a; i >= b; --i)
#define MOD(a, b) (a) % (b)
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define println(a) (cout << (a) << '\n')

using namespace std;

const int inf = 1e9;
const ll inf_ll = 1e17;

void solve() {
    str s; cin >> s;
    ll cnt0 = 0, cnt1 = 0;
    FOR(i, 0, s.size() - 1) {
        if (s[i] == '1') cnt1++;
        if (s[i] == '0') cnt0++;
    }
    if (cnt0 == cnt1) { println(0); return; }
    println(abs(cnt0 - cnt1));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) { solve(); }
    return 0;
}
