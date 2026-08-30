class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;

    bool dfs(int node, int parent) {

        visited[node] = true;

        for(int neighbor : graph[node]) {

            if(neighbor == parent)
                continue;

            if(visited[neighbor])
                return false;

            if(!dfs(neighbor, node))
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1)
            return false;

        graph.resize(n);
        visited.resize(n, false);
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(!dfs(0, -1))
            return false;
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                return false;
        }

        return true;
    }
};