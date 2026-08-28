class Solution {
public:

    void dfs(vector<vector<char>>& arr, int i, int j) {

        int n = arr.size();
        int m = arr[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m)
            return;

        if(arr[i][j] == '0')
            return;

        arr[i][j] = '0';

        dfs(arr, i + 1, j);
        dfs(arr, i - 1, j);
        dfs(arr, i, j + 1);
        dfs(arr, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {

        int count = 0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1') {

                    count++;

                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};