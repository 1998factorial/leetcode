bool dp[500][500];

//dp[i][j] = true iff s[0...i-1] matches p[0...j-1]
class Solution {
public:
	int n,m;
	bool isMatch(string s, string p) {
		n = s.size(),m = p.size();
		memset(dp,false,sizeof(dp));
		dp[0][0] = true;
		for(int i = 0; i < m; i++){
			if(p[i] == '*'){
				if(dp[0][i])dp[0][i+1] = true;
				else if(i > 0)dp[0][i+1] = dp[0][i-1]; //....x*
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(p[j] == '.' || p[j] == s[i])
					dp[i+1][j+1] = dp[i][j];
				else if(p[j] == '*'){
					if(j > 0){
						if(p[j-1] != s[i] && p[j-1] != '.') //skip p[j-1,j]
							dp[i+1][j+1] = dp[i+1][j-1];
						else //either skip or match at least one 
							dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j-1];
					}
				}
			}
		}
		return dp[n][m];
	}
};

//more consice one
class Solution{
public:
	bool dp[500][500];
	int n,m;
	bool isMatch(string s, string p) {
		n = s.size(),m = p.size();
		memset(dp,false,sizeof(dp));
		dp[0][0] = true;
		for(int i = 0; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(p[j-1] == '*'){
					dp[i][j] = (j > 1 && dp[i][j-2]) || (i && dp[i-1][j] && j > 1 && (s[i-1] == p[j-2] || p[j-2] == '.'));
				}
				else{
					dp[i][j] = i && dp[i-1][j-1] && (p[j-1] == '.' || p[j-1] == s[i-1]);
				}
			}
		}
		return dp[n][m];
	}
};
