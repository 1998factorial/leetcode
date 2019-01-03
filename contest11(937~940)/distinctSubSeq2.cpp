typedef long long int64;
class Solution {
public:
    int distinctSubseqII(string s) {
        int ans = 0,n = s.size();
        int64 mod = 1e9 + 7;
		//abc 7, abcb 13, abcbe 27, abcbeb 54-7
        vector<int64> dp(n,0);
        dp[0] = 1;
        for(int i = 1; i < n; i++){
        	int first = -1,j = i-1;
        	while(j >= 0 && s[j] != s[i])--j;
        	if(j < 0){ //no s[i]
        		dp[i] = (2*dp[i-1] + 1 + mod) % mod;
        	}
        	else if(j == 0){ //last s[i] is first
        		dp[i] = (2*dp[i-1] + mod) % mod;
        	}
        	else{ //double count
        		dp[i] = (2*dp[i-1] - dp[j-1] + mod) % mod;
        	}
        }
        ans = dp[n-1];
        return (ans + mod) % mod;
    }
};