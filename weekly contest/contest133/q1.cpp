//sort by manhattan distance
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> a;
        for(int i = 0; i < R;i++){
            for(int j=0;j<C;j++){
                a.push_back({i,j});
            }
        }
        sort(a.begin(),a.end(),[&](vector<int>& x, vector<int>& y){
            return abs(x[0]-r0)+abs(x[1]-c0)<abs(y[0]-r0)+abs(y[1]-c0);
        });
        return a;
    }
};