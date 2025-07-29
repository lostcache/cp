/*
ID: harshde2
LANG: C++
TASK: fence6
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


const int MAXN = 110;
int N;
int len[MAXN];
vector<int> end0[MAXN], end1[MAXN];
int endpointID[MAXN][2];
map<set<int>, int> endpointMap;
int currentEndpoint = 0;

vector<pair<int,int>> graph[2*MAXN];

int main() {
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int s, l, n1, n2;
        cin >> s >> l >> n1 >> n2;
        len[s] = l;
        end0[s].resize(n1);
        end1[s].resize(n2);
        for (int j = 0; j < n1; j++) cin >> end0[s][j];
        for (int j = 0; j < n2; j++) cin >> end1[s][j];
    }

    for (int s = 1; s <= N; s++) {
        set<int> ep0, ep1;
        ep0.insert(s);
        for (int f : end0[s]) ep0.insert(f);
        ep1.insert(s);
        for (int f : end1[s]) ep1.insert(f);

        if (endpointMap.count(ep0) == 0) endpointMap[ep0] = ++currentEndpoint;
        if (endpointMap.count(ep1) == 0) endpointMap[ep1] = ++currentEndpoint;

        endpointID[s][0] = endpointMap[ep0];
        endpointID[s][1] = endpointMap[ep1];
    }

    for (int s = 1; s <= N; s++) {
        int u = endpointID[s][0];
        int v = endpointID[s][1];
        graph[u].emplace_back(v, len[s]);
        graph[v].emplace_back(u, len[s]);
    }

    int ans = INT_MAX;

    for (int u = 1; u <= currentEndpoint; u++) {
        for (auto &[v, w] : graph[u]) {
            if (u < v) {
                // Dijkstra from u to v excluding edge u-v
                vector<int> dist(currentEndpoint + 1, INT_MAX);
                priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

                dist[u] = 0;
                pq.emplace(0, u);

                while (!pq.empty()) {
                    auto [curDist, cur] = pq.top();
                    pq.pop();
                    if (curDist > dist[cur]) continue;
                    if (cur == v) break;

                    for (auto &[nxt, cost] : graph[cur]) {
                        if ((cur == u && nxt == v) || (cur == v && nxt == u)) continue; // skip this edge
                        int nd = curDist + cost;
                        if (nd < dist[nxt]) {
                            dist[nxt] = nd;
                            pq.emplace(nd, nxt);
                        }
                    }
                }

                if (dist[v] != INT_MAX) {
                    ans = min(ans, dist[v] + w);
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

