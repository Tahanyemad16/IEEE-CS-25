#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> visited;
int maxCost = 0;

void dfs(int u, int currentCost) {
    visited[u] = true;
    maxCost = max(maxCost, currentCost);
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        int cost = adj[u][i].second;
        if (!visited[v]) {
            dfs(v, currentCost + cost);
        }
    }
    visited[u] = false;
}

int main() {
    int n;
    cin >> n;
    adj.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
    dfs(0, 0);
    cout << maxCost << endl;
    return 0;
}
