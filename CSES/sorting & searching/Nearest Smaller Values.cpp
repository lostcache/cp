#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#define ll long long
#define vec vector
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define vi vector<int>
#define vii vector<pii>
#define vll vector<ll>
#define vvl vector<vl>
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

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio_init;

int main() {
    ll n; cin >> n;
    vll a(n); FOR(i, 0, n-1) { cin >> a[i]; }
    stack<pll> s; vll res(n);
    FOR(i, 0, n-1) {
        while (!s.empty() && (s.top().first >= a[i])) s.pop();
        if (s.empty()) res[i]=0;
        else res[i]=s.top().second;
        s.push({a[i], i+1});
    }
    FOR(i, 0, n-1) { print(res[i]); print((i==n-1?"\n":" "));}
    return 0;
}

