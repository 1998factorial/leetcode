/*
Given a string,
your task is to count how many palindromic 
substrings in this string.

The substrings with different start indexes or 
end indexes are counted as different substrings even 
they consist of same characters.

eg. "aaa" => a,a,a,aa,aa,aaa => 6
*/
class Solution {
public:
    int countSubstrings(string s) {
    	int n = s.size();
    	if(n == 0)
    		return 0;
    	int count = n;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i = 0; i < n; i++)
        	dp[i][i] = true;
        //dp formula:
        //dp[i][j] = (s[i] == s[j]) and dp[i+1][j-1]
        //i <= j
        for(int i = 0; i < n-1; i++){
        	dp[i][i+1] = (s[i] == s[i+1]);
        	count += dp[i][i+1];
        }
        for(int k = 2; k < n; k++){
        	for(int i = 0; i < n-k; i++){
        		dp[i][i+k] = (s[i] == s[i+k] and dp[i+1][i+k-1]);
        		count += dp[i][i+k]; 
        	}
        }
        return count;
    }
};