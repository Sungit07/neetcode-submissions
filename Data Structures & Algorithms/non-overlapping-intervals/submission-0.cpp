class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int count = 0;

        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {

            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart >= prevEnd) {
                prevStart = currStart;
                prevEnd = currEnd;
            }

            else {
                count++;
                if (currEnd < prevEnd) {
                    prevStart = currStart;
                    prevEnd = currEnd;
                }
            }
        }

        return count;
    }
};