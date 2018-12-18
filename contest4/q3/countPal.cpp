/*
Input: 
S = 'bccb'
Output: 6
Explanation: 
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.

Input: 
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
Output: 104860361
Explanation: 
There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
*/

class Solution {
public:
    int countPalindromicSubsequences(string s) {
    	int n = s.size();
    	if(n == 0)return 0;
    	if(n == 1)return 1;
    	vector<vector<int>> dp(n,vector<int>(n,0));
    	long int mod = 1000000007;
    	for(int i = 0; i < n; i++){
    		dp[i][i] = 1;
    	}
    	for(int k = 1; k < n; k++){
    		for(int i = 0; i < n-k; i++){
    			int j = i+k;
    			if(s[i] == s[j]){
    				dp[i][j] = 2*dp[i+1][j-1];
    				int l = i+1, r = j-1;
    				while(l < j and s[l] != s[i])++l;
    				while(r > i and s[r] != s[j])--r;
    				if(l == r)dp[i][j] += 1; //once
    				else if(l < r)dp[i][j] -= dp[l+1][r-1]; //at least twice
    				else dp[i][j] += 2; //none
    			}else{
    				dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
    			}
    			dp[i][j] = (dp[i][j] + mod) % mod; //avoid negative
    		}
    	}
    	return dp[0][n-1];
    }
};





