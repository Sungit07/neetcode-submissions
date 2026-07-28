class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        if(s[0]=='0' || s.empty()) return 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            int curr = s[i-1]-'0';
            int dd = (s[i-2]-'0')*10+(s[i-1]-'0');
            if(curr >0 && curr < 10){
                dp[i]+=dp[i-1];
            }
            if(dd>9 && dd<27){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};
