#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Cell {
    int x, y;
};

int n, m;
vector<vector<char>> labyrinth;
vector<vector<int>> monsterTime;
vector<vector<bool>> visited;
vector<char> path;
bool foundExit = false;

vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<char> dirChars = {'D', 'U', 'R', 'L'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void calculateMonsterTime(vector<Cell> &monsters) {
    vector<vector<bool>> monsterVisited(n, vector<bool>(m, false));
    vector<Cell> queue = monsters;
    int time = 0;

    while (!queue.empty()) {
        vector<Cell> nextQueue;
        for (Cell cell : queue) {
            int x = cell.x, y = cell.y;
            if (!isValid(x, y) || labyrinth[x][y] == '#' || monsterVisited[x][y]) continue;
            monsterVisited[x][y] = true;
            monsterTime[x][y] = time;
            for (auto [dx, dy] : directions) {
                nextQueue.push_back({x + dx, y + dy});
            }
        }
        queue = nextQueue;
        time++;
    }
}

void dfs(int x, int y, int time) {
    if (foundExit || !isValid(x, y) ||  labyrinth[x][y] == '#' || visited[x][y] || monsterTime[x][y] <= time) return;
    if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
        foundExit = true;
        return;
    }
    visited[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + directions[d].first, ny = y + directions[d].second;
        path.push_back(dirChars[d]);
        dfs(nx, ny, time + 1);
        if (foundExit) return;
        path.pop_back();
    }
    visited[x][y] = false;
}

int main() {
    cin >> n >> m;
    labyrinth = vector<vector<char>>(n, vector<char>(m));
    monsterTime = vector<vector<int>>(n, vector<int>(m, INT_MAX));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    int startX, startY;
    vector<Cell> monsters;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A') {
                startX = i;
                startY = j;
            } else if (labyrinth[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }

    calculateMonsterTime(monsters);
    dfs(startX, startY, 0);

    if (foundExit) {
        cout << "YES\n";
        cout << path.size() << "\n";
        for (char c : path) cout << c;
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
