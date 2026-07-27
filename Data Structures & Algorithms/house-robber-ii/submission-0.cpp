class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n][2];
        if(n==1) return nums[0];
        dp[0][1] = nums[0];
        dp[0][0] = 0;
        for(int i=1;i<n-1;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0]+nums[i];
        }
        int a1=max(dp[n-2][0],dp[n-2][1]);
        dp[1][1]=nums[1];
        dp[1][0]=0;
        for(int i=2;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0]+nums[i];
        }
        int a2 = max(dp[n-1][0],dp[n-1][1]);
        return max(a1,a2);
    }
};
