class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        vector<string> ans;
        map<int,map<char,int>> cnt;
        for(int i = 0; i < n; i++){
            int m = A[i].size();
            for(int j = 0; j < m; j++){
                cnt[i][A[i][j]]++;
            }
        }
        vector<char> all;
        for(char i = 'a'; i <= 'z'; i++){
            bool in = true;
            for(int j = 0; j < n; j++){
                if(!cnt[j][i]){
                    in = false;
                    break;
                }
            }
            if(in)all.push_back(i);
        }
        int k = all.size();
        for(int j = 0; j < k; j++){
            int mi = 1000;
            for(int i = 0; i < n; i++)mi = min(mi,cnt[i][all[j]]);
            for(int i = 0; i < mi; i++){
                string t = "";
                t += all[j];
                ans.push_back(t);
            }
        }
        return ans;
    }
};