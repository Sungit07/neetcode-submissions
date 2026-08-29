class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>> &heights,vector<vector<bool>> &visited,int r,int c){
        if(visited[r][c]) return;
        visited[r][c] =true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            if(visited[nr][nc])
                continue;
            if(heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0);
        }

        for(int j = 0; j < m; j++) {
            dfs(heights, pacific, 0, j);
        }
        for(int i = 0; i < n; i++) {
            dfs(heights, atlantic, i, m - 1);
        }

        for(int j = 0; j < m; j++) {
            dfs(heights, atlantic, n - 1, j);
        }
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
