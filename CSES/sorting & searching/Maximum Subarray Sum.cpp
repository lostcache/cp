#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

#define ll long long
#define vec vector
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define pb push_back
#define FOR(i, a, b) for(ll i=(a); i<(b); ++i)
#define FORD(i, a, b) for(ll i=(a); i>(b); --i)
#define SORT(a) sort((a).begin(), (a).end());
#define println(a) cout << (a) << endl;
#define print(a) cout << (a);

const ll MOD = 1000000007;
const int inf = 1e9;
const ll ll_inf = 1e18;

using namespace std;

int main() {
    ll n; cin >> n;
    vl a(n);
    FOR(i, 0, n) cin >> a[i];
    ll curr = 0;
    ll mx = -ll_inf;
    FOR(i, 0, n) {
        curr = max(curr+a[i], a[i]);
        mx = max(mx, curr);
    }
    println(mx);
    return 0;
}

