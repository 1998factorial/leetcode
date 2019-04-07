
int INF = 1 << 30;
class Solution {
public:
    bool p[2000][2000];
    int dp[2000]; //dp[i] = # minimal cut for s[0...i-1]
    int n;
    int minCut(string s) {
        n = s.size();
        memset(p,false,sizeof(p));
        memset(dp,INF,sizeof(dp));
        for(int i = 0; i < n; i++)p[i][i] = true;
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n-len; i++){
                int j = i+len-1;
                if(s[i] == s[j]){
                    if(i == j-1)p[i][j] = true;
                    else p[i][j] = p[i+1][j-1];
                }
            }
        }
        dp[1] = 0; //single element does not need a cut
        for(int i = 2; i <= n; i++){
            dp[i] = INF;
            for(int j = i-1; j >= 0; j--){
                if(p[j][i-1]){
                    if(j > 0)dp[i] = min(dp[i],dp[j]+1);
                    else dp[i] = min(dp[i],dp[j]);
                }
            }    
        }
        return dp[n];
    }
};