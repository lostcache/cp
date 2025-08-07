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

void update_fen(vl &fen, ll del, ll idx, ll n) {
    ll i = idx;
    while (i <= n){
        fen[i]+=del;
        i += (i & -i);
    }
}

ll get_sum(vl &fen, ll a) {
    ll res=0;
    ll i=a;
    while(i>0) {
        res+=fen[i];
        i-=(i&-i);
    }
    return res;
}

void init_fen(vl &fen, ll n) {
    FOR(i, 1, n) {
        ll j = i + (i&-i);
        if (j <= n)
            fen[j]+=fen[i];
    }
}

int main() {
    ll n,q; cin>>n>>q;
    vl a(n+1); FOR(i, 1, n) cin >> a[i];
    // init tree
    vl fen = a;
    FOR(i, 1, n) {
        ll j = i + (i & -i);
        if (j <= n) fen[j]=fen[j]+fen[i];
    }
    while (q--) {
        ll t,x,y; cin >>t>>x>>y;
        if (t==1) {
            update_fen(fen, y-a[x], x, n);
            a[x]=y;
        } else if (t==2) {
            cout << get_sum(fen, y) - get_sum(fen, x-1) << endl;
        }
    }
    return 0;
}

