class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total=0;
        for(int i=0;i<n;i++) total+=nums[i];
        if(total%2!=0) return false;
        total/=2;
        vector<bool> dp(total+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int j=total;j>=num;j--){
                if(dp[j-num]){
                    dp[j]=true;
                }
            }
        }
        return dp[total];
    }
};
