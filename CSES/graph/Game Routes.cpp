#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    queue<int> q;
    for (int u = 1; u <= n; ++u) {
        if (deg[u] == 0)
            q.push(u);
    }

    vector<int> ord;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ord.push_back(u);
        for (auto v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0)
                q.push(v);
        }
    }

    vector<int> dp(n + 1, 0);
    const int MOD = 1e9 + 7;
    dp[1] = 1;
    for (int u : ord) {
        for (int v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
