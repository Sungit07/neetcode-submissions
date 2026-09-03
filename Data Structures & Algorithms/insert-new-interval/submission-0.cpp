class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int a = newInterval[0];
        int b = newInterval[1];

        vector<vector<int>> ans;
        bool inserted = false;

        for (auto interval : intervals) {

            int x = interval[0];
            int y = interval[1];
            if (y < a) {
                ans.push_back({x, y});
            }
            else if (x > b) {

                if (!inserted) {
                    ans.push_back({a, b});
                    inserted = true;
                }

                ans.push_back({x, y});
            }
            else {
                a = min(a, x);
                b = max(b, y);
            }
        }
        if (!inserted) {
            ans.push_back({a, b});
        }

        return ans;
    }
};