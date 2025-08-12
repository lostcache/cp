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
    string s; cin >> s;
    vl f(26, 0);
    for (char c: s) { f[c - 'A']++; }
    ll mx = *max_element(f.begin(), f.end());
    if (mx>(s.size()+1)/2) { println(-1); return 0; }
    ll prev = -1; string res = "";
    FOR(j, 1, s.size()) {
        bool found=false;
        FOR(i, 0, 25) {
            if (f[i]==0 || i == prev) continue;
            f[i]--; ll rem_mx = *max_element(f.begin(), f.end());
            if (rem_mx <= ((s.size()-res.size())/2)) {
                res+=char(i+'A'); prev=i; found=true; break;
            }
            f[i]++;
        }
        if (!found) { println(-1); return 0; };
    }
    println(res);
    return 0;
}

