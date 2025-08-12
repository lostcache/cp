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

int main() {
    ll n; cin >> n;
    if (n == 1) { ll ai; cin >> ai; println(ai); return 0; }
    vl a(n); FOR(i, 0, n-1) cin >> a[i];
    ll res = ll_inf;
    FOR(mask, 1, (1 << n) - 2) {
        ll g1=0, g2=0;
        FOR(i, 0, n-1) {
            if ((1 << i) & mask) g1+=a[i];
            else g2+=a[i];
        }
        res = min(res, abs(g1-g2));
    }
    println(res);
    return 0;
}

