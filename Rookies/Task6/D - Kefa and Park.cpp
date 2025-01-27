#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> cats;
vector<bool> visited;
int n, m;
int result = 0;

void dfs(int node, int consecutiveCats) {
    if (consecutiveCats > m) return;

    bool isLeaf = true;
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            isLeaf = false;
            if (cats[neighbor]) {
                dfs(neighbor, consecutiveCats + 1);
            } else {
                dfs(neighbor, 0);
            }
        }
    }

    if (isLeaf) {
        result++;
    }
}

int main() {
    cin >> n >> m;

    cats.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cats[i];
    }

    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.resize(n, false);

    if (cats[0]) {
        dfs(0, 1);
    } else {
        dfs(0, 0);
    }

    cout << result << endl;

    return 0;
}
