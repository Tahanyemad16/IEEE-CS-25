#include <iostream>
#include <queue>
using namespace std;

pair<int, int> toCoordinates(const string& square) {
    int x = square[0] - 'a';
    int y = square[1] - '1';
    return {x, y};
}

int minKnightMoves(const string& start, const string& end) {
    auto startCoord = toCoordinates(start);
    auto endCoord = toCoordinates(end);

    if (startCoord == endCoord) return 0;

    bool visited[8][8];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            visited[i][j] = false;

    queue<pair<int, int>> q;
    queue<int> movesQueue;

    q.push(startCoord);
    movesQueue.push(0);
    visited[startCoord.first][startCoord.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int moves = movesQueue.front(); movesQueue.pop();

        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (abs(dx * dy) == 2) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                        if (nx == endCoord.first && ny == endCoord.second) {
                            return moves + 1;
                        }

                        if (!visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                            movesQueue.push(moves + 1);
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    int results[T];

    for (int i = 0; i < T; ++i) {
        string start, end;
        cin >> start >> end;
        results[i] = minKnightMoves(start, end);
    }

    for (int i = 0; i < T; ++i) {
        cout << results[i] << endl;
    }

    return 0;
}
