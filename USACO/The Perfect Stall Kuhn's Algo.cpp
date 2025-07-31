/*
ID: harshde2
LANG: C++
TASK: stall4
*/

#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <unordered_set>
#include <climits>
#include <tuple>
#include <unordered_map>

using namespace std;

#define vec vector
#define ll long long

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b); i >= a; i--)
#define F0Rd(i,a) for (int i = (a); i >= 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())

#define INF 1e9
#define LL_INF 45e17
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define pA first
#define pB second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define ll long long
#define MOD (int)(2e+9+11)
#define SET(vec, val, size) for (int i = 0; i < size; i++) vec[i] = val;
#define SET2D(arr, val, dim1, dim2) F0R(i, dim1) F0R(j, dim2) arr[i][j] = val;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;


const int MAX_COWS = 201;
const int MAX_STALLS = 201;

vector<int> cow_preferences[MAX_COWS];
int stall_assigned_to[MAX_STALLS];
bool visited[MAX_STALLS];

int num_cows, num_stalls;

bool try_match(int cow) {
    for (int stall : cow_preferences[cow]) {
        if (visited[stall]) continue;
        visited[stall] = true;

        // if stall is unassigned or previous cow can be reassigned
        if (stall_assigned_to[stall] == -1 || try_match(stall_assigned_to[stall])) {
            stall_assigned_to[stall] = cow;
            return true;
        }
    }
    return false;
}

int main() {
    ifstream cin("stall4.in");
    ofstream cout("stall4.out");

    cin >> num_cows >> num_stalls;

    for (int cow = 1; cow <= num_cows; ++cow) {
        int count;
        cin >> count;
        while (count--) {
            int stall;
            cin >> stall;
            cow_preferences[cow].push_back(stall);
        }
    }

    memset(stall_assigned_to, -1, sizeof(stall_assigned_to));

    int max_matchings = 0;
    for (int cow = 1; cow <= num_cows; ++cow) {
        memset(visited, 0, sizeof(visited));
        if (try_match(cow)) max_matchings++;
    }

    cout << max_matchings << "\n";

    return 0;
}

