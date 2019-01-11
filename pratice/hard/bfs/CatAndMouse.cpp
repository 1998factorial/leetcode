const int N = 50;
int dp[N][N][2];

struct state{
    int x,y,z;
};

class Solution {
public:
    
    bool all(int a, int b, int c, int t, vector<vector<int>>& g){
        if(c == 0){ //mouse move now
            for(auto& d : g[a]){ //
                if(dp[d][b][1-c] != t)return false;
            }
        }
        else{
            for(auto& d : g[b]){ //
                if(dp[a][d][1-c] != t)return false;
            }
        }
        return true;
    }
    
    bool one(int a, int b, int c, int t, vector<vector<int>>& g){
        if(c == 0){
            for(auto& d : g[a]){ //
                if(dp[d][b][1-c] == t)return true;
            }
        }
        else{
            for(auto& d : g[b]){ //
                if(dp[a][d][1-c] == t)return true;
            }
        }
        return false;
    }
    
    int catMouseGame(vector<vector<int>>& g) {
        int n = g.size();
        queue<state> q; //state search
        memset(dp,0,sizeof(dp));
        for(int i = 1; i < n; i++)
            for(int j = 0; j < 2; j++){
                dp[0][i][j] = 1;
                dp[i][0][j] = 1;
                dp[i][i][j] = 2;
                q.push({0,i,j});
                q.push({i,0,j});
                q.push({i,i,j});
            }
        //perform reverse state search
        while(!q.empty()){
            state s = q.front();
            q.pop();
            int a = s.x, b = s.y, c = s.z; //mouse pos, cat pos, turn
            if(c == 0){//mouse's turn
                for(auto& d : g[b]){//cat just finished a move
                    if(!dp[a][d][1-c]){//(a,d,1-c) not determined
                        if(all(a,d,1-c,1,g)){//if all (a,d,1-c)'s next states are 1, then (a,d,1-c) must be 1
                            dp[a][d][1-c] = 1;
                            q.push({a,d,1-c});                            
                        }
                        else if(one(a,d,1-c,2,g)){//if one of (a,d,1-c)'s next state is 2
                            dp[a][d][1-c] = 2;
                            q.push({a,d,1-c});
                        }
                    }
                }
            }
            else{//cat's turn
                for(auto& d : g[a]){//consider all possible previous states
                    if(!dp[d][b][1-c]){//(d,b,1-c) not determined
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
        return dp[1][2][0]; //mouse start at 1 , cat at 2
    } //1 for mouse, 2 for cat, 0 for draw
};

/*
    state (a,b,0) is 1 iff (k,b,1) is 1 for all k adjcent with a
    （a，b，0）当且仅当所有（k，b，1）为老鼠必胜状态时，是必胜状态。（这里k指所有同a相邻的节点）
*/
