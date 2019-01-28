class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> p(n);
        go(ans,n,0,p);
        return ans;
    }
    
    void go(vector<vector<string>>& ans, int n, int i, vector<int>& p){
        if(n == i){
            vector<string> s(n);
            for(int j = 0; j < n; j++){
                for(int k = 0; k < p[j]; k++)s[j] += '.';
                s[j] += 'Q';
                for(int k = p[j]+1; k < n; k++)s[j] += '.';
            }
            ans.push_back(s);
            return;
        }
        for(int j = 0; j < n; j++){
            bool ok = true;
            for(int k = 0; k < i; k++){
                if(p[k] == j || k-i == p[k]-j || k-i == j-p[k]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                p[i] = j;
                go(ans,n,i+1,p);
            }
        }
    }
};