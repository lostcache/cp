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
    ll n; cin >> n;
    vec<tuple<ll, ll, ll>> a(n);
    FOR(i, 0, n-1) { ll x, y; cin >> x >> y; a[i]={x, y, i}; }
    sort(a.begin(), a.end(), [](const tuple<ll, ll, ll> &a, const tuple<ll, ll, ll> &b) {
            if (get<0>(a)==get<0>(b)) return get<1>(a)>get<1>(b);
            return get<0>(a) < get<0>(b);
        });
    vl contains(n, 0), contained(n, 0);
    ll max_end=-1;
    for (auto &t: a) {
        if (get<1>(t) <= max_end) contained[get<2>(t)]=1;
        else max_end = get<1>(t);
    }
    ll min_end=ll_inf;
    FORD(i, n-1, 0) {
        if (get<1>(a[i])>=min_end) contains[get<2>(a[i])]=1;
        else min_end=get<1>(a[i]);
    }
    FOR(i, 0, n-1) { print(contains[i]); print((i==n-1?"\n":" ")); }
    FOR(i, 0, n-1) { print(contained[i]); print((i==n-1?"\n":" ")); }
    return 0;
}

