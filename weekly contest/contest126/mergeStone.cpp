class Solution {
public:
    /*
    1.需要注意，若从N个pile中拿出一个，由于每次merge减少K-1pile，若N-1是K-1的倍数，则可以完成merge，否则不能。
    2.此题显然是dp，容易发现greedy有可能无法实现全局最优。
    3.dp 递归算是容易想到，但是递归条件不容易想到
    4.it is easy to get dp[i][j] = min{dp[i][k]+dp[k+1][j]} for k = i,i+K-1,i+2(K-1)...
    but it is not easy to realise that if(j-i) % (K-1) is 0 then we need to add
    a[i]+a[i+1]+...a[j] to dp[i][j] as all these piles will eventually be merged to 1 pile 
    dp[i][j] = minimal cost to merge a[i]...a[j]
    dp[i][j] = min{dp[i][k] + dp[k+1][j]}
    if(j-i+1)-1 is multiple of K-1 then a[i]...a[j] can eventually be merged to a single pile
    thus, we need to add sum(a[i...j]) to dp[i][j]
    */
    int mergeStones(vector<int>& a, int K) {
        int n = a.size();
        if((n-1) % (K-1) != 0)return -1;
        vector<int> sum(n+1);
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i = 1; i <= n; i++)sum[i] = sum[i-1] + a[i-1];
        for(int m = K; m <= n; m++){
            for(int i = 0; i + m <= n; i++){
                int j = i + m - 1;
                dp[i][j] = INT_MAX;
                for(int k = i; k < j; k += K - 1){
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                if((j-i) % (K-1) == 0)dp[i][j] += sum[j+1] - sum[i];
            }
        }
        return dp[0][n-1];
    }
};