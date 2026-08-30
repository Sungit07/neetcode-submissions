class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto p: prerequisites){
            int course = p[0];
            int pre = p[1];
            graph[pre].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;
            for(int next: graph[course]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return count == numCourses;
    }
};
