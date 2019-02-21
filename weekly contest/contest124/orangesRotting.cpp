class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0,n = grid.size(), m = grid[0].size();
        vector<vector<int>> nxt = grid;
        set<vector<vector<int>>> s;
        s.insert(grid);
        while(1){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == 1 || grid[i][j] == 0)continue;
                    if(i > 0 && grid[i-1][j] == 1)nxt[i-1][j] = 2;
                    if(i < n-1 && grid[i+1][j] == 1)nxt[i+1][j] = 2;
                    if(j > 0 && grid[i][j-1] == 1)nxt[i][j-1] = 2;
                    if(j < m-1 && grid[i][j+1] == 1)nxt[i][j+1] = 2;
                }
            }
            grid = nxt;
            if(s.find(grid) != s.end())break;
            s.insert(grid);
            ans++;
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1)return -1;
        return ans;
    }
};