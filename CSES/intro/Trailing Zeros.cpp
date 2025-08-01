#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define FOR(i, a, b) for(ll i=(a); i<(b); ++i)
#define FORD(i, a, b) for(ll i=(a); i>(b); --i)
#define pll pair<long long, long long>
#define plll pair<long long, pll>

const ll MOD = 1000000007;

using namespace std;

int main() {
    ll n; cin >> n;
    ll p = 5;
    ll ans = 0;
    while (ll q = n/p) {
        ans += q;
        p*=5;
    }

    cout << ans << endl;
}

