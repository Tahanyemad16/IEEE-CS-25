#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> components[MAXN];
int comCount = 0;

void dfs(int node, int id) {
    visited[node] = true;
    components[id].push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor,id);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            comCount++;
            dfs(i, comCount);
        }
    }

    if (comCount == 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << comCount - 1 << endl;

    vector<int> represent;
    for (int i = 1; i <= comCount; ++i) {
        represent.push_back(components[i][0]);
    }

    for (int i = 1; i < represent.size(); ++i) {
        cout << represent[i - 1] << " " << represent[i] << endl;
    }

    return 0;
}
