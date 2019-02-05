class Solution {
public:
    
    void row(vector<vector<int>>& A, int i, int len){
        for(int j = 0; j < len; j++){
            if(A[i][j] == 0)A[i][j] = 1;
            else A[i][j] = 0;
        }
    }
    
    void col(vector<vector<int>>& A, int i, int len){
        for(int j = 0; j < len; j++){
            if(A[j][i] == 0)A[j][i] = 1;
            else A[j][i] = 0;
        }
    }
    
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size(), ret = 0;
        int m = A[0].size();
        
        for(int i = 0; i < n; i++)
            if(A[i][0] == 0)row(A,i,m);
        
        for(int i = 1; i < m; i++){
            int zero = 0, one = 0;
            for(int j = 0; j < n; j++){
                if(A[j][i] == 0)zero++;
                else one++;
            }
            if(zero > one)col(A,i,n);
        }
        
        for(int i = 0; i < n; i++){
            int t = 0;
            for(int j = 0; j < m; j++){
                t = 2*t + A[i][j];
            }
            ret += t;
        }
        return ret;
    }
};