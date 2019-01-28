class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(), ans = 1 << 30;
        vector<vector<int>> dp(n,vector<int>(3));
        for(int i = 0; i < 3; i++)
            dp[n-1][i] = costs[i];
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < 3; j++){
                int next_day = days[i];
                int k = i;
                if(j == 0){
                    next_day += 0;
                }
                else if(j == 1){
                    next_day += 6;
                }
                else{
                    next_day += 29;
                }
                while(k < n && days[k] <= next_day)++k;
                if(k < n){
                    int m = 1 << 30;
                    for(int p = 0; p < 3; p++)
                        m = min(m,dp[k][p]);
                    dp[i][j] = costs[j] + m;
                }
                else dp[i][j] = costs[j];
            }
        }
        for(int i = 0; i < 3; i++)
            ans = min(ans,dp[0][i]);
        return ans;
    }
};