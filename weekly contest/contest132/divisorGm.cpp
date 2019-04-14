class Solution {
public:
    bool divisorGame(int N) {
        bool dp[1001];
        memset(dp,false,sizeof(dp));
        dp[1] = false;
        for(int i = 2; i <= N; i++){
            for(int j = 1; j < i; j++){
                if(i % j == 0)dp[i] |= !dp[i-j];
            }
        }
        return dp[N];
    }
};