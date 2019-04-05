class Solution {
public:
    
    int n;
    int m;
    bool mp[501][501];
    
    
    bool outBound(int i, int j){
        return i < 0 || i >= n || j < 0 || j >= m;
    }
    
    void search(vector<vector<int>>& A, int i, int j){
        if(outBound(i,j))return;
        if(mp[i][j])return;
        mp[i][j] = true;
        for(int v = -1; v < 2; v++){
            for(int w = -1; w < 2; w++){
                int x = i+v, y = j+w;
                if(abs(x-i) == abs(y-j))continue;
                if(outBound(x,y))continue;
                if(A[x][y])
                    search(A,x,y);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        n = A.size();
        m = A[0].size();
        memset(mp,false,sizeof(mp));
        int ret = 0;
        //first row & last row
        for(int j = 0; j < m; j++){
            if(A[0][j])
                search(A,0,j);
            if(A[n-1][j])
                search(A,n-1,j);
        }
        for(int i = 0; i < n; i++){
            if(A[i][0])
                search(A,i,0);
            if(A[i][m-1])
                search(A,i,m-1);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(A[i][j] && !mp[i][j])ret++;
            }
        }
        return ret;
    }
};