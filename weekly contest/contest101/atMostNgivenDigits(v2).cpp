int dp[15][3];

class Solution {
public:
    //dp[i][0] = # si < Ni
    //dp[i][1] = # si = Ni
    //dp[i][2] = # si no restrict
    vector<int> A;
    int len,m;
    int atMostNGivenDigitSet(vector<string>& D, int n) {
        A.clear();
        m = D.size();
        while(n)
            A.push_back(n % 10), n /= 10;
        len = A.size();
        memset(dp,0,sizeof(dp));
        dp[0][2] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < len+1; i++){
            int Ai = A[i-1];
            for(int j = 0; j < m; j++){
                int Si = D[j][0]-'0';
                if(Si < Ai){
                    dp[i][0] += dp[i-1][2];
                    dp[i][2] += dp[i-1][2];
                }
                else if(Si == Ai){
                    dp[i][1] += dp[i-1][0] + dp[i-1][1];
                    dp[i][2] += dp[i-1][2];
                }
                else{
                    dp[i][2] += dp[i-1][2];
                }
            }

        }
        int ret = 0;
        for(int i = 1; i < len; i++)ret += dp[i][2];
        return ret + dp[len][0] + dp[len][1];
    }
};