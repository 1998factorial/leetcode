class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int count = 1,n = nums.size();
        vector<int> ans;
        if(!n)return ans;
        vector<int> a(n,0);
        int index = 0;
        for(int i = 0; i < n; i++){
            ++a[nums[i]-1];
            if(a[nums[i]-1] > 1)ans.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(!a[i])ans.push_back(i+1);
        }
        return ans;
    }
};