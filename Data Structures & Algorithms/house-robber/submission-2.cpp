class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int dp[2][2];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(int i=1;i<n;i++){
            dp[1][1] = dp[0][0]+nums[i];
            dp[1][0] = max(dp[0][1],dp[0][0]);
            dp[0][0]=dp[1][0];
            dp[0][1]=dp[1][1];
        }
        return max(dp[1][0],dp[1][1]);
    }
};
