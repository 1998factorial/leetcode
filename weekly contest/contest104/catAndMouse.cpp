const int N = 50;
int dp[N][N][2];

struct state{
    int x,y,z;
};

class Solution {
public:
    
    bool one(int a, int b, int c, int t, vector<vector<int>>& g){
        if(c == 0){//mouse 
            for(auto& d : g[a]){
                if(dp[d][b][1-c] == t)return true;
            }
        }
        else{
            for(auto& d : g[b]){
                if(dp[a][d][1-c] == t)return true;
            }
        }
        return false;
    }
    
    bool all(int a, int b, int c, int t, vector<vector<int>>& g){
        if(c == 0){
            for(auto& d : g[a]){
                if(dp[d][b][1-c] != t)return false;
            }
        }
        else{
            for(auto& d : g[b]){
                if(dp[a][d][1-c] != t)return false;
            }
        }
        return true;
    }
    
    int catMouseGame(vector<vector<int>>& g) {
        int n = g.size();
        queue<state> q;
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                dp[i][0][j] = 1;
                dp[0][i][j] = 1;
                dp[i][i][j] = 2;
                q.push({i,0,j});
                q.push({0,i,j});
                q.push({i,i,j});
            }
        }
        while(!q.empty()){
            state s = q.front();
            int a = s.x, b = s.y, c = s.z; //mouse, cat , turn
            q.pop();
            if(c == 0){//mouse's turn
                for(auto& d : g[b]){
                    if(!dp[a][d][1-c]){
                        if(all(a,d,1-c,1,g)){
                            dp[a][d][1-c] = 1;
                            q.push({a,d,1-c});
                        }
                        else if(one(a,d,1-c,2,g)){
                            dp[a][d][1-c] = 2;
                            q.push({a,d,1-c});
                        }
                    }
                }
            }
            else{//cat's move
                for(auto& d : g[a]){
                    if(!dp[d][b][1-c]){
                        if(all(d,b,1-c,2,g)){
                            dp[d][b][1-c] = 2;
                            q.push({d,b,1-c});
                        }
                        else if(one(d,b,1-c,1,g)){
                            dp[d][b][1-c] = 1;
                            q.push({d,b,1-c});
                        }
                    }
                }
            }
        }
        return dp[1][2][0];// mouse at 1, cat at 2, mouse's turn
    } // 1 for mouse, 2 for cat, 0 for draw
};