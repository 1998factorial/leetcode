class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int n = a.size(), ans = 0;
        if(!n)return 0;
        vector<vector<int>> dp(n,vector<int>(2));
        if(a[n-1] == 0)dp[n-1][0]++;
        else dp[n-1][1]++;
        for(int i = n-2; i >= 0; i--){
            if(a[i]) dp[i][1] = dp[i+1][1] + 1, dp[i][0] = dp[i+1][0];
            else dp[i][1] = dp[i+1][1], dp[i][0] = dp[i+1][0] + 1;
        }
        if(dp[0][0] == dp[0][1])return n;
        for(int i = 1; i < n; i++){
            if(dp[i][0] == dp[i][1] && ans < n-i)ans = n-i;
        }
        for(int k = n-1; k >= ans; k--){
            for(int i = 0; i < n-k; i++){
                int j = i+k;
                if(dp[i][0] - dp[j][0] == dp[i][1] - dp[j][1])return k;
            }
        }
        return ans;
    }
};