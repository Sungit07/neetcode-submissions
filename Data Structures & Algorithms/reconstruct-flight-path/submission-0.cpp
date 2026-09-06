class Solution {
public:

    unordered_map<string, priority_queue<
        string,
        vector<string>,
        greater<string>
    >> graph;

    vector<string> ans;

    void dfs(string airport) {

        while (!graph[airport].empty()) {

            string next = graph[airport].top();
            graph[airport].pop();

            dfs(next);
        }

        ans.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto &ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};