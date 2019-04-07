class Solution {
public:
    string removeOuterParentheses(string s) {
        //get all vaild strings
        int cnt = 0;
        int n = s.size();
        string t = "";
        vector<string> p;
        int i = 0, j = 0;
        while(i < n && j < n){
            if(!cnt && i < j){
                p.push_back(t),t = "";
                i = j;
            }
            else{
                if(s[j] == '(')cnt++;
                if(s[j] == ')')cnt--;
                t += s[j];
                j++;
            }
        }
        if(t != "")p.push_back(t);
        string ret = "";
        for(string x : p){
            int m = x.size();
            for(int i = 0; i < m; i++){
                if(i == 0 || i == m-1)continue;
                ret += x[i];
            }
        }
        return ret;
    }
};