//dp[i][j] = maximal coins collected when burst all balloons in a[i..j]
//first thought : dp[i][j] = max{dp[i][k-1] + dp[k+1][j] + a[k-1]*a[k]*a[k+1]}
//but cant do, as we don't know which balloons in a[i...k-1] and a[k+1...j] will 
//burst lastly.
//so, dp[i][j] = min{dp[i][k-1]+dp[k+1][j]+a[i-1]*a[k]*a[j+1]}
//(letting a[k] be the last ballon to burst in a[i...j])

//q312
typedef long long int64;

int64 dp[500][500];

class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n = a.size();
        if(!n)return 0;
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++){
            dp[i][i] = a[i];
            if(i-1 >= 0)dp[i][i] *= a[i-1];
            if(i+1 < n)dp[i][i] *= a[i+1];
        }
        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len <= n; i++){
                int j = i + len - 1;
                dp[i][j] = - 1;
                for(int k = i; k <= j; k++){
                    int64 ret = a[k];
                    if(i-1 >= 0)ret *= a[i-1];
                    if(j+1 < n)ret *= a[j+1];
                    if(k-1 >= i)ret += dp[i][k-1];
                    if(k+1 <= j)ret += dp[k+1][j];
                    dp[i][j] = max(dp[i][j],ret);
                }
            }
        }
        return dp[0][n-1];
    }
};