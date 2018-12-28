/*
We are given non-negative integers nums[i] which are written on a chalkboard.  
Alice and Bob take turns erasing exactly one number from the chalkboard, with Alice starting first.  
If erasing a number causes the bitwise XOR of all the elements of the chalkboard to become 0, then that player loses.  
(Also, we'll say the bitwise XOR of one element is that element itself, and the bitwise XOR of no elements is 0.)

Also, if any player starts their turn with the bitwise XOR of all the elements of the chalkboard equal to 0, 
then that player wins.

Return True if and only if Alice wins the game, assuming both players play optimally.
*/
//Q810
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        //Alice losses when one number left / all numbers XOR to 0
    	int n = nums.size();
    	if(!n)return true; //start with nothing
    	//we consider two cases
    	//case1 all numbers in nums xor to 0 => Alice wins
    	//case2 else if n is even => Alice wins
    	/*
    		proof of case2
		
			suppose n is even:
    		S = XOR(nums), if S is not 0 then there is at least 1
    		bit equals to 1 , say S[b] = 1. We can split nums into 
    		group U and V where all numbers in U at [b] = 0 and 
    		all numbers in V at [b] = 1. Then there must be an odd 
    		number of elements in V. Thus, impling that there is an 
    		odd number of elements in U. (|U| + |V| = n and n is even)
    		This implies that there exists at least one number in U 
    		such that [b] = 0. Alice can then earse a number in V to force 
    		the xor on [b] for all remaining numbers to be 0, Bob will have to 
    		erase a number in V to not lose. |V| will always be odd until 
    		|V| becomes 0. At this moment, Alice will win the game.

    		if n is odd, |V| is odd and |U| will be even. By removing 
    		number in |V| or |U|, Bob will always fall into case 1 or case 2.
    		Then Bob will win. 
    	*/
    	int x = 0;
    	for(int i = 0; i < n; i++)x ^= nums[i];
    	return !x || n % 2 == 0;
    }
};