//q920
typedef long long int64;
const int mod = 1e9+7;
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
    /*
    dp[n][l] = number of play lists that have n distinct songs and length l
	
	observe:
	(n = l) -> dp[n][l] = n!
	(n < l) -> dp[n][l] = n * dp[n-1][l-1] + (N-n) * dp[n][l-1]
    */
    	
    }
};