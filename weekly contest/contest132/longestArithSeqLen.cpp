class Solution {
public:
    int n;
    //dp[i][j] = maximal length of a-seq ending at A[i] with diff j
    int longestArithSeqLength(vector<int>& A) {
        n = A.size();
        int ret = -1;
        map<int,map<int,int>> dp;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = A[j]-A[i];
                if(!dp[j][diff])dp[j][diff] = 1;
                dp[i][diff] = dp[j][diff] + 1;
                ret = max(ret,dp[i][diff]);
            }
        }
        return ret;
    }
};