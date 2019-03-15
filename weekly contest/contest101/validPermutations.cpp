typedef long long int64;
int64 mod = 1e9+7;

int64 dp[205][205];

class Solution {
public:
    int n;
    int numPermsDISequence(string s) {
        n = s.size();
        //dp[i][j] = # of ways to permute i numbers given that the ith number 
        //is the jth smallest number in remaining numbers
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n+1; i++)
        	dp[0][i] = 1;
        for(int i = 0; i < n; i++){
        	if(s[i] == 'D'){
        		for(int j = n-i; j >= 1; j--)
        			dp[i+1][j] = (dp[i+1][j+1] + dp[i][j+1] + mod) % mod;
        	}
        	else{
        		for(int j = 1; j <= n-i; j++)
        			dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] + mod) % mod;
        	}
        }
        return dp[n][1];
    }
};