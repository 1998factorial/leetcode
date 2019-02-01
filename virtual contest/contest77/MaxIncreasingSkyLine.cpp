class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        if(!n)return ans;
        int m = grid[0].size();
        vector<int> front(m), side(n);
        for(int i = 0; i < m; i++){
            int mx = -1;
            for(int j = 0; j < n; j++)
                if(mx < grid[j][i])mx = grid[j][i];
            front[i] = mx;
        }
        for(int i = 0; i < n; i++){
            int mx = -1;
            for(int j = 0; j < m; j++)
                if(mx < grid[i][j])mx = grid[i][j];
            side[i] = mx;
        }
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(front[j] < side[i]) ans += (front[j] - grid[i][j]);
                else ans += (side[i] - grid[i][j]);
            }
        }    
        
        
        return ans;
    }
};