class Solution {

    boolean dfs(int limit, int[][] grid, boolean[][] visited, int i, int j) {
        int n = grid.length;
        int m = grid[0].length;

        if (i < 0 || i >= n || j < 0 || j >= m ||
            visited[i][j] || grid[i][j] > limit) {
            return false;
        }

        if (i == n - 1 && j == m - 1) {
            return true;
        }

        visited[i][j] = true;

        return dfs(limit, grid, visited, i - 1, j) ||
               dfs(limit, grid, visited, i + 1, j) ||
               dfs(limit, grid, visited, i, j - 1) ||
               dfs(limit, grid, visited, i, j + 1);
    }

    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int l = Integer.MAX_VALUE;
        int h = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                l = Math.min(l, grid[i][j]);
                h = Math.max(h, grid[i][j]);
            }
        }

        while (l < h) {
            int mid = l + (h - l) / 2;

            boolean[][] visited = new boolean[n][m];

            if (dfs(mid, grid, visited, 0, 0)) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
}