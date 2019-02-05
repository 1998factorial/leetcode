//q899
/*
if K = 1: we can rotate any length of substring s
if K > 1: we can swap adjcent chars (thus resulted string will be sorted)
*/
class Solution {
public:
    string orderlyQueue(string s, int K) {
        if(K > 1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans = s;
        int n = s.size();
        for(int i = 1; i < n; i++){
            ans = min(ans,s.substr(i)+s.substr(0,i));
        }
        return ans;
    }
};