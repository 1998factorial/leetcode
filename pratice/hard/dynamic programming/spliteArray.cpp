//q410
typedef long long int64;
const int64 INF = 3e11;
class Solution {
public:
    int n;
    
    int splitArray(vector<int>& A, int m) {
        n = A.size();
        //dp[i][j] = minimal largest sum given m = j over A[0...i]
        //dp[i][j] = min{ max{A[i]+A[i-1]+...A[k],dp[k-1][j-1]} | j<=k<i}
        vector<vector<int64>> dp(n+1,vector<int64>(m+1));
        for(int i = 1; i <= n; i++)dp[i][1] = A[i-1] + dp[i-1][1];
        for(int j = 2; j <= m; j++){
            for(int i = n; i >= j; i--){
                int64 minimal = INF;
                for(int k = i-1; k >= j-1; k--){
                    minimal = min(minimal,max(dp[k][j-1],dp[i][1]-dp[k][1]));
                }
                dp[i][j] = minimal;
            }
        }
        return dp[n][m];
    }
};