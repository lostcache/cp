#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> vst(n + 1, 0);  // 0 = unvisited, 1 = visiting, 2 = visited
    vector<int> paren(n + 1, -1);
    vector<int> cycle;

    function<bool(int)> dfs = [&](int u) {
        vst[u] = 1;
        for (auto v : adj[u]) {
            if (vst[v] == 0) {
                paren[v] = u;
                if (dfs(v)) return true;
            } else if (vst[v] == 1) {
                // Cycle found, reconstruct it
                cycle.push_back(v);
                int cur = u;
                while (cur != v) {
                    cycle.push_back(cur);
                    cur = paren[cur];
                }
                cycle.push_back(v);
                reverse(cycle.begin(), cycle.end());
                return true;
            }
        }
        vst[u] = 2;
        return false;
    };

    bool found = false;
    for (int i = 1; i <= n; ++i) {
        if (vst[i] == 0) {
            if (dfs(i)) {
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cycle.size() << "\n";
        for (int i = 0; i < (int)cycle.size(); ++i) {
            if (i > 0) cout << " ";
            cout << cycle[i];
        }
        cout << "\n";
    }

    return 0;
}

