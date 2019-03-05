/*
此题与括号match异曲同工，很可惜在周赛上并没有ac
*/
class Solution {
public:
    bool isValid(string S) {
        int n = S.size();
        stack<int> s;
        for(int i = 0; i < n; i++){
            int k = S[i]-'a';
            if(k == 0)s.push(k);
            else{
                if(s.size() > 0){
                    if(k == 1){
                        if(s.top() == k-1)s.pop(),s.push(k);
                        else return false;
                    }
                    else{
                        if(s.top() == k-1)s.pop();
                        else return false;
                    }
                }
                else return false;
            }
        }
        return s.size() == 0;
    }
};