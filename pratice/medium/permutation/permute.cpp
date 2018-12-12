class Solution{
public:
	void generate(vector<int> nums, vector<vector<int>> ans, int index){
		//invariant: nums[0..index-1] have been permuted
		if(index == nums.size()){
			//one permutation done
			ans.push_back(nums);
			return;
		}
		for(int i = index; i < nums.size(); i++){
			//for all elements after nums[index] (including index)
			//swap its position with nums[index]
			swap(nums[index],nums[i]);
			generate(nums,ans,index+1);// recurse,extend
			swap(nums[index],nums[i]);// set back and keep going
		}
	}
	vector<vector<int>> permute(vector<int>& nums){
		//assume all elements in nums are distinct
		//generate all permutation of nums
		vector<vector<int>> ans;
		generate(nums,ans,0);
		return ans;
	}
};
/*
key observation:
	there are n! such permutation (given distinct)
	It is not hard to come up with a solution that perform in O(n!).
	
	consider A[1..N], for A[k], we have N-k choices, thus we try all N-k numbers at
	A[k] by swapping the old(A[k]) with itself and all numbers after it.
	After swapping, A[k] is fixed, so we proceed on A[k+1] and so forth.

	When k = N, we are done.
*/

