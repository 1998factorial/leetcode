class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> l;
        map<int,int> r;
        map<int,int> n;
        int max_num = 0;
        int min_len = 100000;
        for(int i = 0; i < nums.size(); i++){
            if(!l.count(nums[i]))
                l[nums[i]] = i;
            if(!n.count(nums[i]))
                n[nums[i]] = 1;
            else if(n.count(nums[i]))
                ++n[nums[i]];
        }
        
        for(int i = nums.size()-1; i >= 0; i--){
            max_num = max(max_num,n[nums[i]]);
            if(!r.count(nums[i]))
                r[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(n[nums[i]] == max_num){
                min_len = min(min_len,r[nums[i]]-l[nums[i]]+1);
            }
        }
        
        return min_len;
    }
};