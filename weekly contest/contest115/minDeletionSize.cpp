class Solution {
public:
    
    bool sorted(vector<string>& A, int n, vector<int>& keep, int len){
        if(!len)return true; //delete all
        for(int i = 0; i < n; i++){
            for(int j = 0; j < len-1; j++){
                if(A[i][keep[j]] > A[i][keep[j+1]])return false;
            }
        }
        return true;
    }
    
    void dfs(vector<string>& A, int n, int m, vector<int>& keep, int i, int& ans){
        if(i == m){
            int len = keep.size();
            if(m-len < ans && sorted(A,n,keep,len)){
                ans = m-len;
            }
        }
        else{
            for(int j = i; j < m; j++){
                dfs(A,n,m,keep,j+1,ans);
                keep.push_back(j);
                dfs(A,n,m,keep,j+1,ans);
                keep.pop_back();
            }
        }
    }
    
    int minDeletionSize(vector<string>& A) {
        int ans = 0, n = A.size();
        if(!n)return ans;
        int m = A[0].size();
        ans = m;
        //n words, each with length m
        vector<int> keep; //indices of cols that we gonna keep
        dfs(A,n,m,keep,0,ans);
        return ans;
    }
};

//dfs is too slow, we use dp
//find min deletion length == find max sorted sequence

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), ans = 0;
        int m = A[0].size();
        vector<int> dp(m,1);
        for(int i = m-2; i >= 0; i--){
            for(int j = i+1; j < m; j++){
                bool f = true;
                for(int k = 0; k < n; k++){
                    if(A[k][i] > A[k][j]){
                        f = false;
                        break;
                    }
                }
                if(f)dp[i] = max(dp[i],dp[j]+1);
            }
        }
        for(int i = 0; i < m; i++)ans = max(ans,dp[i]);
        return m-ans;
    }
};