#include <iostream>
#include <vector>
using namespace std;

const int n= 8;
vector<string> board(n);
int solutions = 0;

bool isSafe(int row, int col, vector<bool> &columns, vector<bool> &diag1, vector<bool> &diag2) {
    return !columns[col] && !diag1[row - col + n- 1] && !diag2[row + col];
}

void solve(int row, vector<bool> &columns, vector<bool> &diag1, vector<bool> &diag2) {
    if (row == n) {
        solutions++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (board[row][col] == '*' || !isSafe(row, col, columns, diag1, diag2)) continue;
        columns[col] = diag1[row - col + n- 1] = diag2[row + col] = true;
        solve(row + 1, columns, diag1, diag2);
        columns[col] = diag1[row - col + n- 1] = diag2[row + col] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    for (int i = 0; i < n; i++)
       cin >> board[i];

    vector<bool> columns(n, false), diag1(2 * n- 1, false), diag2(2 * n- 1, false);

    solve(0, columns, diag1, diag2);

    cout << solutions << endl;

    return 0;
}
