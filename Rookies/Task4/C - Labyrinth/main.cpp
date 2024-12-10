#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 1000;
int n, m;
char laby[MAX_SIZE][MAX_SIZE];
bool vis[MAX_SIZE][MAX_SIZE];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && laby[x][y] != '#' && !vis[x][y];
}

void BFS(int startX, int startY, int endX, int endY) {
    queue<pair<int, int>> q;
    vector<vector<pair<int, char>>> parent(n, vector<pair<int, char>>(m, {-1, ' '}));
    q.push({startX, startY});
    vis[startX][startY] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == endX && y == endY) {
            cout << "YES\n";
            string path = "";
            while (!(x == startX && y == startY)) {
                path += parent[x][y].second;
                int px = parent[x][y].first / m;
                int py = parent[x][y].first % m;
                x = px;
                y = py;
            }
            reverse(path.begin(), path.end());
            cout << path.length() << "\n" << path << "\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY)) {
                vis[newX][newY] = true;
                parent[newX][newY] = {x * m + y, dir[i]};
                q.push({newX, newY});
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int startX, startY, endX, endY;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> laby[i][j];
            if (laby[i][j] == 'A') {
                startX = i;
                startY = j;
            } else if (laby[i][j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }

    BFS(startX, startY, endX, endY);

    return 0;
}
