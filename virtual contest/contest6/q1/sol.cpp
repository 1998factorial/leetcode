class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int h = A.size();//height
        if(!h)
        	return NULL;
        int w = A[0].size();//width
        if(h == 1 and w = 1)
        	return A;
        vector<vector<int>> B(w,vector<int>(h,0));
        for(int i = 0; i < w; i++){
        	for(int j = 0; j < h; j++){
        		B[i][j] = A[j][i];
        	}	
        }
        return B;
    }
};