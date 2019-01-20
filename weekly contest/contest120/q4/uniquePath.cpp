class Solution {
public:
    void dfs(int x,int y,int x_end,int y_end,int cur,int count,vector<vector<bool>>& seen,vector<vector<int>>& a,int& ans,int n, int m){
        if(x < 0 || x >= n || y < 0 || y >= m)return; //out of map
        if(a[x][y] == -1 || seen[x][y])return; //not obstacle or visited square
        if(cur+1 == count && x == x_end && y == y_end){
            ++ans;
            return; //done
        }
        else if(cur+1 != count && x == x_end && y == y_end)return;
        seen[x][y] = true;
        int c = cur;
        dfs(x+1,y,x_end,y_end,c+1,count,seen,a,ans,n,m);
        dfs(x-1,y,x_end,y_end,c+1,count,seen,a,ans,n,m);
        dfs(x,y+1,x_end,y_end,c+1,count,seen,a,ans,n,m);
        dfs(x,y-1,x_end,y_end,c+1,count,seen,a,ans,n,m);
        seen[x][y] = false;
    }
    
    int uniquePathsIII(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        if(!n)return ans;
        int m = a[0].size();
        int count = 0;
        int x_end = -1, y_end = -1,x_start = -1, y_start = -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j] != -1)++count;
                if(a[i][j] == 2)x_end = i, y_end = j;
                if(a[i][j] == 1)x_start = i, y_start = j;
            }
        if(x_start == -1 || y_start == -1 || x_end == -1 || y_end == -1)return 0;
        int cur = 0;
        vector<vector<bool>> seen(n,vector<bool>(m,false));
        dfs(x_start,y_start,x_end,y_end,cur,count,seen,a,ans,n,m);
        
        return ans;
    }
};