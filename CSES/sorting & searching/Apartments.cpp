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
    ll n, m, k; cin >> n >> m >> k; vl appli(n), app(m);
    FOR(i, 0, n) cin >> appli[i]; FOR(i, 0, m) cin >> app[i];
    SORT(appli); SORT(app);
    ll ni=0, mi=0, match=0;
    while (ni < n && mi < m) {
        if (app[mi] >= appli[ni]-k && app[mi] <= appli[ni]+k) {
            mi++; ni++; match++;
        }
        else if (app[mi] > appli[ni]+k) { ni++; }
        else { mi++; }
    }
    cout << match << endl;
    return 0;
}

