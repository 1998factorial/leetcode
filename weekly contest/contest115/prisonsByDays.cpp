class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> ans;
        ans = cells;
        int mod = ((N-1) % 14) + 1;
        for(int i = 0; i < mod; i++){
            for(int j = 0; j < 8; j++){
                if(j == 0 || j == 7)ans[j] = 0;
                else{
                    if(cells[j-1] == cells[j+1])ans[j] = 1;
                    else ans[j] = 0;
                }
            }
            cells = ans;
        }
        return ans;
    }
};