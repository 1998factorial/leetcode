class Solution {
public:
    //for each connected component, ans += component.size() - 1
    int dfs(vector<vector<int>>& stones, vector<bool>& seen, int m){
        if(seen[m])return 0;
        seen[m] = true;
        int n = stones.size(),ret = 1;
        for(int i = 0; i < n; i++){
            if(stones[m][0] == stones[i][0] || stones[m][1] == stones[i][1]){
                ret += dfs(stones,seen,i);
            }
        }
        return ret;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(),ans = 0;
        vector<bool> seen(n,false);
        for(int i = 0; i < n; i++){
            int ret = dfs(stones,seen,i);
            if(ret > 1)ans += ret - 1;
        }
        return ans;
    }
};
