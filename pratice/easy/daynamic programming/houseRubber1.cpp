//q198
//Input: [1,2,3,1]
//Output: 4
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        vector<int> dp0(n,0),dp1(n,0);
        dp1[0] = nums[0];
        for(int i = 1; i < n; i++){
        	dp1[i] = dp0[i-1] + nums[i];
        	dp0[i] = max(dp0[i-1],dp1[i-1]);
        }
        return max(dp0[n-1],dp1[n-1]);
    }
};