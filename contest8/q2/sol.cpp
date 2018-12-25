//(a,b),(c,d) iff b < c
/*
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

//(a,b), make sure that b is as small as possible
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),cmp); //ascending order by a[i][1]
        int n = a.size(),ans = 0; 
        if(!n)return ans; //empty
        int pre = a[0][1];
        ans = 1;
        for(int i = 1; i < n; i++){
        	if(a[i][0] > pre){
        		pre = a[i][1];
        		++ans;
        	}
        }
        return ans;
    }
    static bool cmp(vector<int>& a, vector<int>& b){
    	return a[1] < b[1];
    }
};