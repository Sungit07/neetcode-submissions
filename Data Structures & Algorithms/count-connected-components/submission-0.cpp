class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b)
            return;

        if(rank[a] < rank[b])
            swap(a, b);

        parent[b] = a;

        if(rank[a] == rank[b])
            rank[a]++;
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if(find(u) != find(v)) {
                unite(u, v);
                components--;
            }
        }

        return components;
    }
};