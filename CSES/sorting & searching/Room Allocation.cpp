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

struct Dur {
    ll a, b, idx;
};

int main() {
    ll n; cin >> n;
    vec<Dur> durs(n);
    FOR(i, 0, n-1) { ll a, b; cin >> a >> b; durs[i]={a,b,i}; }
    sort(durs.begin(), durs.end(), [](const Dur &a, const Dur &b) {
                if (a.a == b.a) return a.b < b.b;
                return a.a < b.a;
            }
        );
    priority_queue<pll, vec<pll>, greater<>> pq;
    vl ass(n); ll used=0;
    for (auto &c: durs) {
        if (!pq.empty() && pq.top().first < c.a) {
            auto [b, r] = pq.top(); pq.pop();
            ass[c.idx]=r;
            pq.push({c.b, r});
        } else {
            used++;
            ass[c.idx]=used;
            pq.push({c.b, used});
        }
    }

    println(used);
    FOR(i, 0, ass.size()-1) {
        print(ass[i]);
        if (i == ass.size()-1) print("\n");
        else print(" ");
    }
    return 0;
}

