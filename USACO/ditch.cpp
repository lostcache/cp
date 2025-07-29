/*
ID: harshde2
LANG: C++
TASK: ditch
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

int N, M;
int cap[201][201];
int paren[201];

int bfs(int s, int t) {
    memset(paren, -1, sizeof(paren));
    paren[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, 1e9});

    while (!q.empty()) {
        auto [cur, flow] = q.front(); q.pop();

        for (int next=1; next<=M; ++next) {
            // if not visited and flow exists
            if (paren[next] == -1 && cap[cur][next] > 0) {
                // mark as visited;
                paren[next] = cur;
                // records the possible flow which is min(bottleneck) out of all;
                int new_flow = min(flow, cap[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int main() {
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);

    cin >> N >> M;

    memset(cap, 0, sizeof(cap));

    for (int i=0; i<N; ++i) {
        int u, v, c; cin >> u >> v >> c;
        cap[u][v] += c;
    }

    int flow=0;
    int new_flow;

    while ((new_flow = bfs(1, M))) {
        flow += new_flow;

        int cur = M;
        while (cur != 1) {
            int prev = paren[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }

    cout << flow << endl;

    return 0;
}

