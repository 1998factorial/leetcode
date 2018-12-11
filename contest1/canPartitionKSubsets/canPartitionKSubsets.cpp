class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //a brute force solution
        int sum = 0;
        for(int i = 0; nums.size(); i++)sum += nums[i];
        if(k <= 0 || sum % k != 0)return false; //handle edge case
        vector<bool> v(nums.size(),false); //keep tracks with which number is used
        return search(nums,v,k,0,0,sum/k);
    }
    bool search(vector<int>& nums, vector<bool> v, int k, int index, int sum, int target){
        if(k == 1)return true; //1 group does not need partition
        if(sum == target)return search(nums,v,k-1,0,0,target); //start from the begining
        for(i = index; i < nums.size(); i++){
            if(!v[i] and nums[i] + sum <= target){// nums[i] not used and can be put in this group
                v[i] = true;// use it now 
                if(search(nums,v,k,i+1,sum + nums[i],target))return true;
                // store nums[i] in current group and search given that nums[i] is used 
                v[i] = false; // also search if nums[i] is not used
            }
        }
        return false;
    }
}