#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int q = queries.size();
        
        sort(intervals.begin(), intervals.end());
        
        vector<pair<int, int>> sq(q);
        for(int i = 0; i < q; i++) {
            sq[i] = {queries[i], i};
        }
        sort(sq.begin(), sq.end());
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(q, -1);
        int idx = 0;
        
        for(int i = 0; i < q; i++) {
            int q_val = sq[i].first;
            int q_idx = sq[i].second;
            
            while(idx < n && intervals[idx][0] <= q_val) {
                int size = intervals[idx][1] - intervals[idx][0] + 1;
                pq.push({size, intervals[idx][1]});
                idx++;
            }
            
            while(!pq.empty() && pq.top().second < q_val) {
                pq.pop();
            }
            
            if(!pq.empty()) {
                ans[q_idx] = pq.top().first;
            }
        }
        
        return ans;
    }
};
