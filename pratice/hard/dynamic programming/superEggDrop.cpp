//q887
//given K eggs and N floors
//find the minimal number of moves needed to find floor F

//solution 1 (TLE)
/*
    dp[k][n] = minimal number of moves given k eggs and n floors
    dp[k][n] = 1 + min(max(dp[k-1][i-1],dp[k][n-i]) for 1<=i<=n)
    base cases:
    dp[0][i] = 0 no egg
    dp[1][i] = i only one egg => try all i floors
    dp[i][1] = 1 only one floor
*/
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp((K+1),vector<int>(N+1));
        for(int i = 1; i < N+1; i++)
            dp[1][i] = i;
        for(int i = 1; i < K+1; i++)
            dp[i][1] = 1;
        for(int k = 2; k <= K; k++){ //O(KN^2)
            for(int n = 2; n <= N; n++){
                int m = 1 << 29;
                for(int i = 1; i <= n; i++){
                    m = min(m,max(dp[k-1][i-1],dp[k][n-i]));
                }
                dp[k][n] = 1 + m;
            }
        }
        return dp[K][N]; 
    }
};
//solution 2 
/*
    dp[m][k] = maximal number of floors we can check given 
    m tries and k eggs

    dp[m][k] = 1 + dp[m-1][k] + dp[m-1][k-1]
    
*/
class Solution {
public:
    int superEggDrop(int K, int N){
        //1<=m<=N
        vector<vector<int>> dp((N+1),vector<int>(K+1));
        int m = 1;
        while(dp[m][K] < N){//O(N*K)
            for(int k = 1; k <= K; k++){
                dp[m][k] = 1 + dp[m-1][k] + dp[m-1][k-1];
            }   
        }
        return m;
    }
};
//solution 3
//infact m is redundant and we can optimize to 1D dp
class Solution{
public:
    int superEggDrop(int K, int N){
        vector<int> dp(K+1);
        int m = 0;
        for(; dp[K] < N; m++)
            for(int k = K; k >= 1; k--)
                dp[k] += dp[k-1] + 1;
        return m;
    }
};

