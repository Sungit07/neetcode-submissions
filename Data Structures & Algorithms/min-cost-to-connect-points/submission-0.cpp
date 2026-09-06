class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;

        vector<int> md(n, INT_MAX);
        vector<bool> visited(n, false);
        
        int ans = 0;
        int curr = 0;
        visited[0] = true;

        for (int step = 1; step < n; step++) {
            int next_node = -1;
            int min_d = INT_MAX;

            for (int k = 0; k < n; k++) {
                if (!visited[k]) {
                    int dist = abs(points[curr][0] - points[k][0]) + abs(points[curr][1] - points[k][1]);
                    if (dist < md[k]) {
                        md[k] = dist;
                    }
                    if (md[k] < min_d) {
                        min_d = md[k];
                        next_node = k;
                    }
                }
            }

            if (next_node == -1) break;

            curr = next_node;
            visited[curr] = true;
            ans += min_d;
        }
        
        return ans;
    }
};
