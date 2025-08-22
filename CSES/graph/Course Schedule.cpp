#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
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
    vector<int> ord;
    for (int u = 1; u <= n; ++u) {
        if (deg[u] == 0)
            q.push(u);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ord.push_back(u);

        for (int v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)ord.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < (int)ord.size(); ++i) {
            if (i)
                cout << " ";
            cout << ord[i];
        }
        cout << endl;
    }

    return 0;
}
