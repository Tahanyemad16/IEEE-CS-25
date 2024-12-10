#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int rows, cols;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
char direction[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];
int ptime[MAXN][MAXN], mtime[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char directions[] = {'U', 'D', 'L', 'R'};

bool isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != '#';
}

void bfsPlayer(int startX, int startY) {
    queue<pair<int, int>> playerQueue;
    playerQueue.push({startX, startY});
    visited[startX][startY] = true;
    ptime[startX][startY] = 0;

    while (!playerQueue.empty()) {
        auto current = playerQueue.front();
        playerQueue.pop();
        int x = current.first, y = current.second;

        if (x == 0 || x == rows - 1 || y == 0 || y == cols - 1) {
            cout << "YES\n";
            string path = "";
            while (!(x == startX && y == startY)) {
                path += direction[x][y];
                auto prev = parent[x][y];
                x = prev.first;
                y = prev.second;
            }
            reverse(path.begin(), path.end());
            cout << path.length() << "\n" << path << "\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i], newY = y + dy[i];
            if (isValid(newX, newY) && !visited[newX][newY] &&
                (ptime[x][y] + 1 < mtime[newX][newY] || mtime[newX][newY] == -1)) {
                visited[newX][newY] = true;
                direction[newX][newY] = directions[i];
                parent[newX][newY] = {x, y};
                ptime[newX][newY] = ptime[x][y] + 1;
                playerQueue.push({newX, newY});
            }
        }
    }

    cout << "NO\n";
}


void bfsMonsters(vector<pair<int, int>> monsterPos) {
    queue<pair<int, int>> monsterQueue;
    for (auto monster : monsterPos) {
        monsterQueue.push(monster);
        mtime[monster.first][monster.second] = 0;
    }

    while (!monsterQueue.empty()) {
        auto current = monsterQueue.front();
        monsterQueue.pop();
        int x = current.first, y = current.second;

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i], newY = y + dy[i];
            if (isValid(newX, newY) && mtime[newX][newY] == -1) {
                mtime[newX][newY] = mtime[x][y] + 1;
                monsterQueue.push({newX, newY});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> rows >> cols;
    int startX, startY;
    vector<pair<int, int>> monsterPos;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 'M') {
                monsterPos.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ptime[i][j] = -1;
            mtime[i][j] = -1;
        }
    }

    bfsMonsters(monsterPos);
    bfsPlayer(startX, startY);

    return 0;
}
