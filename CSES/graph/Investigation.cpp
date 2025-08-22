#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<long long, int>>> adj(n + 1);
    for (int i = 1; i <= m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    vector<long long> cost(n + 1, 1e17), ways(n + 1, 0);
    vector<int> minFlights(n + 1, 1e9), maxFlights(n + 1, -1e9);
    ways[1] = 1;
    cost[1] = minFlights[1] = maxFlights[1] = 0;
    vector<int> paren(n + 1, -1);
    using State = pair<long long, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    const int MOD = 1e9 + 7;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != cost[u])
            continue;

        for (auto [w, v] : adj[u]) {
            if (d + w < cost[v]) {
                cost[v] = d + w;
                ways[v] = ways[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({cost[v], v});
            } else if (d + w == cost[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }

    cout << cost[n] << " " << ways[n] << " " << minFlights[n] << " "
         << maxFlights[n] << endl;
    return 0;
}
