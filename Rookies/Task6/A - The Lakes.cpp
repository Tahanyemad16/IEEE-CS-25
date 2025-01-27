#include <iostream>
#include <vector>
using namespace std;


int dfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
        return 0;
    }

    int sum= grid[i][j];
    grid[i][j] = 0;

    sum+=dfs(grid, i + 1, j);
    sum+=dfs(grid, i - 1, j);
    sum+=dfs(grid, i, j + 1);
    sum+=dfs(grid, i, j - 1);

    return sum;
}


int main() {
    int t;
    cin>>t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>grid[i][j];
            }
        }

        int maxvolume = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <m; j++) {
                if (grid[i][j] >0) {
                    maxvolume=max(maxvolume,dfs(grid, i, j));
                }
            }
        }
        cout<<maxvolume<<"\n";
    }


    return 0;
}
