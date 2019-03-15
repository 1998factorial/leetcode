//q920
typedef long long int64;
const int mod = 1e9+7;
int64 dp[101][101];
//dp[i][j] = # of play list st it's length is j and contains i distinct songs
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		//dp[n][n] = n!
		for(int j = 1; j <= L; j++){
			for(int i = 1; i <= j && i <= N; i++){
				dp[i][j] = (dp[i-1][j-1] * (N - i + 1) + mod) % mod;
				if(i > K)
					dp[i][j] = (dp[i][j] + (i - K) * dp[i][j-1] + mod) % mod;
			}
		}
		return dp[N][L];	
    }
};