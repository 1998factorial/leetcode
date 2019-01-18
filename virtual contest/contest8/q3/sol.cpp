/*
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(),ans = 0;
        if(!n)return 0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        //dp[i][j] = s[i:j] is pal
        for(int i = 0; i < n; i++)++ans,dp[i][i] = true;

        for(int k = 1; k < n; k++){
        	for(int i = 0; i < n-k; i++){
        		int j = i+k;
        		if(i+1 == j){
        			dp[i][j] = (s[i] == s[j]);
        		}
        		else{ //i+1 < j
        			if(s[i] == s[j])dp[i][j] = dp[i+1][j-1];
        			else dp[i][j] = false;
        		}
        		ans += dp[i][j];
        	}
        }
        return ans;
    }
};