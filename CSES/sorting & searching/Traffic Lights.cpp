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
const int inf = 1e9;
const ll ll_inf = 1e18;
const ll MOD = 1e9+7;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const char cdirs[4] = {'R', 'L', 'D', 'U'};
using namespace std;

int main() {
    ll x, n; cin >> x >> n;
    vl a(n); FOR(i, 0, n-1) cin >> a[i];
    set<ll> s; multiset<ll> ms;
    s.insert(0); s.insert(x); ms.insert(x);
    FOR(i, 0, n-1) {
        ll ai=a[i];
        auto it=s.upper_bound(ai);
        ll right=*it, left=*prev(it);
        ms.erase(ms.find(right-left));
        ms.insert(ai-left); ms.insert(right-ai);
        s.insert(ai);
        print(*ms.rbegin());
        if (i==n) print("\n");
        else print(" ");
    }
    return 0;
}

