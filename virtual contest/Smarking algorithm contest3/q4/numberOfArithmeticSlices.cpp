typedef long long int64;
class Solution {
public:
    
    int find(vector<int>& a, int i, int j, int64 diff, vector<vector<int>>& dp, int n){
        if(dp[i][j] != -1)return dp[i][j];
        int ret = 0;
        for(int k = j+1; k < n; k++){
            int64 d = (int64)a[k]-(int64)a[j];
            if(d == diff){
                ret += 1 + find(a,j,k,diff,dp,n);
            }
        }
        dp[i][j] = ret;
        return ret;
    }
    
    int numberOfArithmeticSlices(vector<int>& a) {
        int ans = 0, n = a.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int64 diff = (int64)a[j]-(int64)a[i];
                ans += find(a,i,j,diff,dp,n);
            }
        }
        return ans;
    }
};