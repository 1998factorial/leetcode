class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,0);
        if(n < 3)
            return 0;
        dp[0] = cost[0],dp[1] = cost[1];
        //dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};