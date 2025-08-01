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
#define pll pair<long long, long long>;
#define plll pair<long long, pll>

const ll MOD = 1000000007;
using namespace std;

ll fast_exp(ll base, ll exp) {
    ll ans = 1;
    while (exp > 0) {
        if ((1 & exp)) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }

    return ans;
}

int main() {
    ll n; cin >> n;
    cout << fast_exp(2, n) << endl;
    return 0;
}

