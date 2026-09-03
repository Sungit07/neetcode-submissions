class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int px = intervals[0][0];
        int py = intervals[0][1];
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            if(a>py){
                ans.push_back({px,py});
                px=a;py=b;
            }
            else{
                py = max(py,b);
            }
        }
        ans.push_back({px,py});
        return ans;
    }
};
