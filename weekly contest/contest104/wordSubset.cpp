class Solution {
public:
    
    bool match(string& a, vector<vector<int>>& t, int m, vector<int>& v){
        int n = a.size();
        vector<bool> u(m,false);
        vector<int> p(26,0);
        for(int j = 0; j < n; j++){
            ++p[a[j]-'a'];
        }
        for(int i = m-1; i >= 0; i--){
            if(u[v[i]])continue;
            for(int j = 0; j < 26; j++)
                if(p[j] < t[i][j])return false;
            u[i] = true;
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        int m = B.size();
        sort(B.begin(),B.end(),cmp);
        vector<vector<int>> t(m,vector<int>(26,0)); //table
        for(int i = 0; i < m; i++){
            int len = B[i].size();
            for(int j = 0; j < len; j++)
                ++t[i][B[i][j]-'a'];
        }
        vector<int> v(m,0);
        for(int i = 0; i < m; i++){
            for(int j = m-1; j >= 0; j--){
                bool f = true;
                for(int k = 0; k < 26; k++){
                    if(t[i][k] > t[j][k]){
                        f = false;
                        break;
                    }
                }
                if(f){
                    v[i] = j;
                    break;
                }
            }
        }
        int n = A.size();
        for(int i = 0; i < n; i++){
            if(match(A[i],t,m,v))
               ans.push_back(A[i]);
        }
        return ans;
    }
    
    static bool cmp(string& a , string& b){
        return a.size() < b.size();
    }
    
};