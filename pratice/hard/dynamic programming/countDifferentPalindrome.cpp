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

/*
	I think this is a pretty hard problem, I could not think of any approach 
	at first. So I start to search solutions to this problem, and after reading 
	their solutions and fully understood them, I wrote the code below.
*/
class Solution {
	/*
		eg. dp('bb') = 2
			dp('bbcacbb') = 2*dp('bcacb')

		dp formula:
		dp[i][j] = # of different palindromes in (s[i:j]) inclusive
		if s[i] != s[j]:
			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] (double count)
		else:
			if s[i] not in s[i+1:j-1]: 
				dp[i][j] = 2 * (dp[i+1][j-1] + 1) (we include pal in s[i+1:j-1] or do not include)
			if s[i] appears in s[i+1:j-1] for exactly once:
				dp[i][j] = 2 * (dp[i+1][j-1] + 1) - 1 (double counted palindrome: s[i])
			if s[i] appears at least twice in s[i+1:j-1]:
				dp[i][j] = 2 * dp[i+1][j-1] - dp[l+1][r-1], where 
				l = min{k|i < k < j and s[k] = s[i]}
				r = max{k|i < k < j and s[k] = s[i]}
				(we double counted the contents in s[l+1:r-1])
	*/		
public:
    int countPalindromicSubsequences(string s) {
    	int n = s.size();
    	if(n == 0)
    		return 0;
    	if(n == 1)
    		return 1;
    	vector<vector<int>> dp(n,vector<int>(n,0));
    	long int mod = 1000000007;
    	for(int i = 0; i < n; i++)
    		dp[i][i] = 1;
    	for(int k = 1; k < n; k++){//(i <= j)
    		for(int i = 0; i < n-k; i++){
    			int j = i+k; 
    			if(s[i] == s[j]){
    				dp[i][j] = 2*dp[i+1][j-1];
    				int l = i+1;
    				int r = j-1;
    				while(l < j and s[l] != s[i])++l;
    				while(r > i and s[r] != s[j])--r;
    				if(l == j and r == i)dp[i][j] += 2; //no s[i]
    				else{
    					if(l == r)dp[i][j] += 1;
    					else dp[i][j] -= dp[l+1][r-1];
    				}
    			}
    			else{
    				dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
    			}
    			dp[i][j] = (dp[i][j] + mod) % mod;
    		}
    	}
    	return dp[0][n-1];
    }
};
