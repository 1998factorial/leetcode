class Solution {
public:
    bool check(vector<vector<int>>& a,int i,int j){
        bool magic = true;
        int sum = a[i][j] + a[i+1][j+1] + a[i+2][j+2];
        for(int k = 0; k < 3; k++){
            if(a[i+k][j]+a[i+k][j+1]+a[i+k][j+2] != sum)
                magic = false;
            if(a[i][j+k]+a[i+1][j+k]+a[i+2][j+k] != sum)
                magic = false;
        }
        if(a[i][j+2] + a[i+1][j+1] + a[i+2][j] != sum)
            magic = false;
        return magic;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = 0;
        int i = 0, j = 0;
        for(i = 0; i < grid.size() - 2; i++){
            for(j = 0; j < grid[i].size() - 2; j++){
                if(check(grid,i,j))
                    ++n;
            }
        }
        return n;
    }
};