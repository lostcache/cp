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

const ll MOD = 1000000007;

using namespace std;

int main() {
    int n; cin >> n;
    vl a(n);
    FOR(i, 0, n) cin >> a[i];
    SORT(a);
    ll ans = 1;
    FOR(i, 1, n) { if(a[i] != a[i-1]) ans++; }
    cout << ans << endl;
    return 0;
}

