class Solution {
public:
    bool inside(int i, int j, int r, int c){
        if(i < 0 || j < 0)return false;
        if(i >= r || j >= c)return false;
        return true;
    }
    //key : right,down,left,up distance increased every 2 dir change
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ans(R*C,vector<int>(2));
        ans[0][0] = r0;
        ans[0][1] = c0;
        int dist = 0, count = 1, dir = 0, time = 0;
        while(count < R*C){
            if(time == 0)dist++;
            time = 1 - time;
            if(dir % 4 == 0){//right
                for(int i = 1; i <= dist; i++){
                    c0++;
                    if(inside(r0,c0,R,C)){
                        ans[count][0] = r0,ans[count][1] = c0;
                        count++;
                    }
                }
            }
            if(dir % 4 == 1){//down
                for(int i = 1; i <= dist; i++){
                    r0++;
                    if(inside(r0,c0,R,C)){
                        ans[count][0] = r0,ans[count][1] = c0;
                        count++;
                    }
                }
            }
            if(dir % 4 == 2){//left
                for(int i = 1; i <= dist; i++){
                    c0--;
                    if(inside(r0,c0,R,C)){
                        ans[count][0] = r0,ans[count][1] = c0;
                        count++;
                    }
                }
            }
            if(dir % 4 == 3){//up
                for(int i = 1; i <= dist; i++){
                    r0--;
                    if(inside(r0,c0,R,C)){
                        ans[count][0] = r0,ans[count][1] = c0;
                        count++;
                    }
                }
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};