/*
Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. 
Moving diagonally is not allowed.
*/

//try dfs

class Solution {
public:
	int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
	int dfs(vector<vector<int>>& A, int i, int j, vector<vector<int>>& dp, int n, int m){
		if(dp[i][j])return dp[i][j]; //computed
		int mx = 0;
		for(int x = 0; x < 4; x++){
			int dj = j + dir[x][0],di = i + dir[x][1];
			if(dj<0 or dj>=m or di<0 or di>=n or A[i][j] >= A[di][dj])continue; //out of bound/not increasing
			mx = max(mx,dfs(A,di,dj,dp,n,m));//see if path start with A[di][dj] is longer
		}
		dp[i][j] = mx+1;
		return mx+1; //plus A[i][j]
	}
    int longestIncreasingPath(vector<vector<int>>& A) {
        int n = A.size(); //height
        if(n == 0)
        	return 0;
        int m = A[0].size(); //width
        if(m == 0)
        	return 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        //dp[i][j] = longestIncreasingPath starting at A[i][j]
        int ans = 0;
        for(int i = 0; i < n; i++)
        	for(int j = 0; j < m; j++)
        		ans = max(ans,dfs(A,i,j,dp,n,m));
        return ans;
    }
};

