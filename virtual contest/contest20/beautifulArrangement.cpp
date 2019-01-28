class Solution {
public:
    
    void dfs(vector<bool>& seen, int i, int N, int& ans){
        if(i == N){
            for(int j = 0; j < N; j++)
                if(!seen[j])return;
            ++ans;
        }
        else{
            for(int k = 0; k < N; k++){
                if(!seen[k]){
                    if((i+1) % (k+1) == 0 || (k+1) % (i+1) == 0){
                        seen[k] = true;
                        dfs(seen,i+1,N,ans);
                        seen[k] = false;
                    }
                }
            }
        }
    }
    
    int countArrangement(int N) {
        int ans = 0;
        vector<bool> seen(N);
        dfs(seen,0,N,ans);
        return ans;
    }
};