#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

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

using namespace std;

int main() {
    ll n, mx; cin >> n >> mx;
    vl a(n);
    FOR(i, 0, n) cin >> a[i];
    SORT(a);
    ll l=0, r=n-1, currCap=0, ans = 0;
    while (l<=r) {
        if (a[l] + a[r] <= mx) { l++; r--; }
        else r--;
        ans++;
    }
    println(ans);
    return 0;
}

