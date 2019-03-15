//q1000

int dp[30][30];
int sum[31];

class Solution {
public:
	//dp[i][j] = min{dp[i][k] + dp[k+1][j]}
	int mergeStones(vector<int>& a, int K) {
		int n = a.size();
		if((n-1) % (K-1) != 0)return -1;
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		for(int i = 1; i <= n; i++)sum[i] = sum[i-1] + a[i-1];
		for(int len = K; len <= n; len++){
			for(int i = 0; i+len <= n; i++){
				int j = i + len - 1;
				dp[i][j] = INT_MAX;
				for(int k = i; k < j; k += K-1)
					dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
				if((j-i) % (K-1) == 0) //merge to one eventually
					dp[i][j] += sum[j+1] - sum[i];
			}
		}
		return dp[0][n-1];
	}
};