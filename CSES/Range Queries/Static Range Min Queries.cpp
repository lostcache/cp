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

const ll MOD = 1e9+7;
const int inf = 1e9;
const ll ll_inf = 1e18;
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const char cdirs[4] = {'R', 'L', 'D', 'U'};

using namespace std;



int main() {
    ll n, q; cin>>n>>q;
    vl a(n+1); FOR(i, 1, n) cin >> a[i];
    ll LOG = floor(log2(n)) + 1;
    vvl st(n+1, vl(LOG+1, 0));
    FOR(i, 1, n) st[i][0]=a[i];
    FOR(k, 1, LOG-1) {
        FOR(i, 1, n-(1<<k) + 1) {
            ll jmp=1<<(k-1);
            st[i][k]=min(st[i][k-1], st[i+jmp][k-1]);
        }
    }
    while (q--) {
        ll a, b; cin>>a>>b;
        ll len = b-a+1, k = floor(log2(len)), jmp=1<<k;
        cout << min(st[a][k], st[b-jmp+1][k]) << endl;
    }
}

