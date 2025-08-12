#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

#define ll long long
#define vec vector
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vvl vector<vl>
#define vll vector<pll>
#define pb push_back
#define FOR(i, a, b) for(ll i=(a); i<=(b); ++i)
#define FORD(i, a, b) for(ll i=(a); i>=(b); --i)
#define SORT(a) sort((a).begin(), (a).end())
#define println(a) (cout << (a) << endl)
#define print(a) (cout << (a))
#define REV(a) reverse((a).begin(), (a).end())

const ll MOD = 1e9+7;
const int inf = 1e9;
const ll ll_inf = 1e18;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const char cdirs[4] = {'R', 'L', 'D', 'U'};

using namespace std;

void hanoi(ll n, ll s, ll t, ll aux, vec<pll> &m) {
    if (n == 1) { m.pb({s, t}); return; }
    hanoi(n-1, s, aux, t, m);
    m.pb({s, t});
    hanoi(n-1, aux, t, s, m);
}

int main() {
    ll n; cin >> n;
    vec<pll> m;
    hanoi(n, 1, 3, 2, m);
    println(m.size());
    for (auto [a, b]: m)
        cout << a << " " << b << endl;
    return 0;
}

