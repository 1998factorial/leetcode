typedef long long int64;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0, n = A.size();
        vector<map<int,int>> dp(n);
        for(int i = 1; i < n; i++){
        	for(int j = 0; j < i; j++){
        		if((int64)A[j] - (int64)A[i] > INT_MAX || (int64)A[j] - (int64)A[i] < INT_MIN)
        			continue;
        		int diff = A[j] - A[i], sum = 0;
        		if(dp[j].find(diff) != dp[j].end())sum = dp[j][diff];
        		dp[i][diff] += 1 + sum;
        		ans += sum;
        	}
        }
        return ans;
    }
};