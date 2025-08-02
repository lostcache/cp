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
    int n, c; cin >> n >> c;
    multiset<ll> ni;
    FOR(i, 0, n) { ll nii; cin >> nii; ni.insert(nii); }
    FOR(i, 0, c) {
        ll cii; cin >> cii;
        auto up = ni.upper_bound(cii);
        if (up == ni.begin()) println(-1)
        else { --up; println(*up); ni.erase(up); }
    }
    return 0;
}

