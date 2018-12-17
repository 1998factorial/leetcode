/*
Given a square array of integers A, 
we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row,
and chooses one element from each row. 
The next row's choice must be in a column 
that is different from the previous row's column by at most one.
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
    	int n = A.size();
    	int min_sum = 1000000;
    	if(n == 0)
    		return 0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        //formula:
        //dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]) + A[i][j]
        for(int i = 0; i < n; i++)
        	dp[0][i] = A[0][i];
        for(int i = 1; i < n; i++){
        	for(int j = 0; j < n; j++){
        		if(j == 0){
        			dp[i][j] = A[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
        		}
        		else if(j == n-1){
        			dp[i][j] = A[i][j] + min(dp[i-1][j-1],dp[i-1][j]);
        		}
        		else{
        			dp[i][j] = A[i][j] + min(min(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]);
        		}
        	}
        }
        for(int j = 0; j < n; j++)
        	min_sum = min(min_sum,dp[n-1][j]);
        return min_sum;
    }
};