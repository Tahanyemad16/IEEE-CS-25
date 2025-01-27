#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> p;
vector<bool> visited;
int n;

void dfs(int node) {
    visited[node] = true;
    int distantRel = p[node] - 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    cin >> n;
    p.resize(n);
    adj.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        int distantRel = p[i] - 1;
        if (i != distantRel) {
            adj[i].push_back(distantRel);
            adj[distantRel].push_back(i);
        }
    }

    int treeCount = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            treeCount++;
        }
    }

    cout << treeCount << endl;

    return 0;
}
