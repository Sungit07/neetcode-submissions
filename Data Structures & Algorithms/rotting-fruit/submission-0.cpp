class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2)
                    q.push({i,j});

                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int ans = 0;

        while(!q.empty() && fresh > 0) {

            int sz = q.size();

            while(sz--) {

                auto [a,b] = q.front();
                q.pop();

                if(a > 0 && grid[a-1][b] == 1) {
                    grid[a-1][b] = 2;
                    fresh--;
                    q.push({a-1,b});
                }

                if(b > 0 && grid[a][b-1] == 1) {
                    grid[a][b-1] = 2;
                    fresh--;
                    q.push({a,b-1});
                }

                if(a < n-1 && grid[a+1][b] == 1) {
                    grid[a+1][b] = 2;
                    fresh--;
                    q.push({a+1,b});
                }

                if(b < m-1 && grid[a][b+1] == 1) {
                    grid[a][b+1] = 2;
                    fresh--;
                    q.push({a,b+1});
                }
            }

            ans++;
        }

        return fresh == 0 ? ans : -1;
    }
};