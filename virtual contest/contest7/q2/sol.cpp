/*
Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
Output: 2
Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the backs are [1,2,4,1,3].
We choose the second card, which has number 2 on the back, and it isn't on the front of any card, so 2 is good.
*/
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        if(n == 1){
        	if(fronts[0] == backs[0])return 0;
        	return min(fronts[0],backs[0]);
        }
        map<int,bool> same;
        for(int i = 0; i < n; i++){
        	if(fronts[i] == backs[i])
        		same[fronts[i]] = true;
        	else{
        		if(!same.count(fronts[i]))same[fronts[i]] = false;
        		if(!same.count(backs[i]))same[backs[i]] = false;
        	}
        }

        int ans = 1 << 30;
        for(int i = 0; i < n; i++){
        	int b = 1 << 30, f = 1 << 30;
        	int c = 0;
        	if(!same[fronts[i]])f = fronts[i];
        	if(!same[backs[i]])b = backs[i];
        	c = min(b,f);
        	ans = min(ans,c);
        }
        if(ans == 1 << 30)return 0;
        return ans;
    }
};