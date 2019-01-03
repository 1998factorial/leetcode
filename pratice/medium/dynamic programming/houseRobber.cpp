//now houses are arranged in a circle
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(),ans = 0;
        if(!n)return ans;
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0],nums[1]);

        vector<int> dp1(n,0),dp0(n,0);
        //we can not rub both nums[0] and nums[n-1]
        //case1 do not rob nums[0]
        dp1[1] = nums[1];
        for(int i = 2; i < n; i++){
        	dp0[i] = max(dp0[i-1],dp1[i-1]);
        	dp1[i] = nums[i] + dp0[i-1];
        }
        ans = max(dp0[n-1],dp1[n-1]);
        //case2 do not rob nums[n-1]
        for(int i = 0; i < n; i++)dp0[i] = 0,dp1[i] = 0;
        dp1[0] = nums[0];
        for(int i = 1; i < n-1; i++){
        	dp0[i] = max(dp0[i-1],dp1[i-1]);
        	dp1[i] = nums[i] + dp0[i-1];
        }
        ans = max(max(dp0[n-2],dp1[n-2]),ans);

        return ans;
    }	
};