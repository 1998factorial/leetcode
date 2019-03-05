class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x = -1,y = -1,ans = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    x = i, y = j;
                    break;
                }
            }
        }
        if(x == -1 || y == -1)return ans;
        //up
        for(int i = 1; i+x < 8; i++){
            if(board[x+i][y] == 'p'){
                ans++;
                break;
            }
            if(board[x+i][y] == 'B')break;
        }
        //right
        for(int i = 1; i+y < 8; i++){
            if(board[x][y+i] == 'p'){
                ans++;
                break;
            }
            if(board[x][y+i] == 'B')break;
        }
        //left
        for(int i = 1; y-i >= 0; i++){
            if(board[x][y-i] == 'p'){
                ans++;
                break;
            }
            if(board[x][y-i] == 'B')break;
        }
        //down
        for(int i = 1; x-i >= 0; i++){
            if(board[x-i][y] == 'p'){
                ans++;
                break;
            }
            if(board[x-i][y] == 'B')break;
        }
        return ans;
    }
};