class Solution {
public:
    vector<int> parent,sz;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(sz[a]>sz[b]) swap(a,b);
        sz[a]+=sz[b];
        parent[b]=a;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        sz.resize(n+1,1);
        for(int i=1;i<=n;i++) parent[i]=i;
        int x=-1,y=-1;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            if(find(u)==find(v)){
                x=u;
                y=v;
            }
            unite(u,v);
        }
        if(x==-1 && y==-1) return {};
        return {x,y};
    }
};
