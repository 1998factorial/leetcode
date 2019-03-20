class Solution {
public:
    int n;
    
    int solve(string s, int i, int j){
        if(i+1 == j)return 1;
        int ret = 0, a = i+1, b = a, cnt = 0;
        while(a < j){
            for(; b < j; b++){
                if(s[b] == '(')cnt++;
                else cnt--;
                if(cnt == 0)break;
            }
            ret += solve(s,a,b);
            b++;
            a = b;
        }
        return 2*ret;
    }
    
    int scoreOfParentheses(string s) {
        n = s.size();
        int ret = 0;
        int i = 0, cnt = 0, j = 0;
        while(i < n){
            for(; j < n; j++){
                if(s[j] == '(')cnt++;
                else cnt--;
                if(cnt == 0)break;
            }
            ret += solve(s,i,j);
            j++;
            i = j;
        }
        return ret;
    }
};