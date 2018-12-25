/*
Input: A = [2, 4, 5, 10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
*/
typedef long long int64;
class Solution {
public:
    int find(vector<int>& A, int m){
        int n = A.size(),ret = -1;
        for(int i = 0; i < n; i++){
        	if(A[i] == m){
        		ret = i;
        		break;
        	}
        }
        return ret;
    }

    int numFactoredBinaryTrees(vector<int>& A) {
        int64 mod = 1e9 + 7;
        int n = A.size();
        int64 ret = 0;
        if(!n)return 0;
        sort(A.begin(),A.end());
        vector<int64> dp(n,1); //careful of type
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < i; j++){
        		int index = -1;
                if(A[i] % A[j] == 0)index = find(A,A[i]/A[j]);
        		if(index > -1){
        			dp[i] = (dp[i] + dp[j]*dp[index]) % mod;
        		}
        	}
        	ret = (ret + dp[i]) % mod;
        }
        return (ret + mod) % mod;
    }
};