/*
Input: "123456579"
Output: [123,456,579]

Input: "11235813"
Output: [1,1,2,3,5,8,13]

Input: "112358130"
Output: []
Explanation: The task is impossible.
*/

//a dfs solution

class Solution {
public:
	bool valid(string S, vector<int>& nums, int curr){
		int n = S.size();
		int m = nums.size();
		if(curr >= n and nums.size() >= 3)
			return true;
		int maxSplitSize = (S[curr] == '0') ? 1 : 10;
		 //if start with 0, then on its own, else its max_length for int (10)
		for(int i = 1; i <= maxSplitSize and i + curr <= n; i++){
			long long num = stoll(S.substr(curr,i));
			//stoll convert a string to integer
			//substr(start,len)
			if(num > INT_MAX)continue;
			//check fib property
			//nums[m-1] + nums[m-2] must be num
			if(m >= 2 and nums[m-1] + nums[m-2] != num)continue;
			nums.push_back(num);
			if(valid(S,nums,curr+i))return true;
			nums.pop_back();//
		}
		return false;
	}

    vector<int> splitIntoFibonacci(string S) {
        vector<int> nums;
        if(valid(S,nums,0));
        	return nums;
        vector<int> empty;
        return empty;
    }
};