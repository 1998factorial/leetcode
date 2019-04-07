//经典鹰🥚问题

//K eggs, N floors
//dp[i][j] = "maximal number of floors we can check if we have i tries and j eggs"
//dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + 1
//dp[0][j] = dp[i][0] = 0
int dp[10000][101];
class Solution{
public:
    int superEggDrop(int K, int N){
    	memset(dp,0,sizeof(dp));
		int ret = 0;
		while(dp[ret][K] < N){ //O(K*N)
			for(int j = 1; j <= K; j++){
				dp[ret+1][j] = dp[ret][j] + dp[ret][j-1] + 1;
			}
			ret++;
		}
		return ret;    	
    }
};


//improve to 1 D
class Solution{
public:
    int superEggDrop(int K, int N){
    	vector<int> dp(K+1);
    	int ret = 0;
    	for(; dp[K] < N; ret++){
    		for(int j = K; j >= 0; j--){
    			dp[j] += dp[j-1] + 1; //as dp[i-1][j] is computed
    		}
    	}
    	return ret;
    }
};


