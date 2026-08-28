class Solution {
public:

    void bfs(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // Put all treasures into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            int v = grid[r][c];

            if(r > 0 && grid[r-1][c] == 2147483647) {
                grid[r-1][c] = v + 1;
                q.push({r-1,c});
            }

            if(c > 0 && grid[r][c-1] == 2147483647) {
                grid[r][c-1] = v + 1;
                q.push({r,c-1});
            }

            if(r < n-1 && grid[r+1][c] == 2147483647) {
                grid[r+1][c] = v + 1;
                q.push({r+1,c});
            }

            if(c < m-1 && grid[r][c+1] == 2147483647) {
                grid[r][c+1] = v + 1;
                q.push({r,c+1});
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        bfs(grid);
    }
};