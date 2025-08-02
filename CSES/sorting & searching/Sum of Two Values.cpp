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

using namespace std;

int main() {
    ll n, t; cin >> n >> t;
    // for this problem unordered_map is slower for some fkn reason!
    map<ll, ll> m;
    FOR(i, 0, n) {
        ll ai; cin >> ai;
        if (m.find(t-ai) != m.end()) {
                cout << m[t-ai] << " " << i+1 << endl;
            return 0;
        }
        m[ai] = i+1;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

