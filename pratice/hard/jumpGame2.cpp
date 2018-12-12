class Solution{
public:
	int getNext(vector<int>& nums, int k){
		if(k + nums[k] >= nums.size() - 1)// can jump to last index at current position
			return nums.size() - 1;

		int opt_pos = k;
		int sum = 0;
		for(int j = k+1; j <= k+nums[k]; j++){
			//for all positions that I can reach
			if(j + nums[j] > sum){
				sum = j + nums[j];
				opt_pos = j;
			}
		}
		return opt_pos;
	}

	int jump(vector<int>& nums){
		int njumps = 0;
		int k = 0;
		while(k < nums.size() - 1){
			k = getNext(nums,k);
			++njumps;
		}
		return njumps;
	}
};
/*
GREEDY SOLN
A = [..,3,5,2,4,..]
say A[k] = 3.
we can reach A[k+1],A[k+2],A[k+3]
we start from A[k+1], choose the one that make k+i+A[k+i] maximal
proof of optimality:
	say a solution is optimal, where there exist a jump from k to j 
	(k+1<=j<=k+A[k]) and j + A[j] is not maximal. Then there exists
	p where (k+1<=p<=k+A[k]) and p + A[p] > j + A[j]. that means, the
	jump from j to some index can also be achieved at position p.
	thus, if we jump to p, the solution will still be optimal.
	This completes the proof.
*/