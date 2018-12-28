//Q835
//array,非常暴力的一题
//fix A, shift B for u in x direction, v in y direction
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(),ans = 0;
        if(!n)return ans;
        for(int u = -n+1; u < n; u++){
        	for(int v = -n+1; v < n; v++){
        		int cur = 0;
        		for(int i = 0; i < n; i++)
        			for(int j = 0; j < n; j++)
        				if(A[i][j] && i+u >= 0 && i+u < n && j+v >= 0 && j+v < n && B[i+u][j+v])++cur;
        		ans = max(cur,ans);
        	}
        }
        return ans;
    }
};