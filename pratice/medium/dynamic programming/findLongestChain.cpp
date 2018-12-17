/*
You are given n pairs of numbers. 
In every pair, the first number is always smaller than 
the second number.

Now, we define a pair (c, d) can follow another pair (a, b) 
if and only if b < c. Chain of pairs can be formed in this fashion.
=> (a,b),(c,d)

Given a set of pairs, find the length longest chain which can be formed. 
You needn't use up all the given pairs. You can select pairs in any order.
*/
class Solution {
public:
	//sort pairs by their ends
    //makes sure that the pairs at the end is not as suitable as
    //pairs at the begining for being a tail
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n == 0)
        	return 0;
        sort(pairs.begin(),pairs.end(),cmp);
        int ans = 1;
        //greedy
        int min_second = pairs[0][1];
        for(int i = 1; i < n; i++){
        	if(min_second < pairs[i][0]){
        		++ans;
        		min_second = pairs[i][1];
        	}
        }
        return ans;
    }

    static bool cmp(vector<int>& a, vector<int>& b){
    	return a[1] < b[1];
    }
};
