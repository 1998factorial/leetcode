class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> ans(2);
        int n = S.size();
        ans[0]++;
        for(int i = 0; i < n; i++){
            if(ans[1]+widths[S[i]-'a'] <= 100)ans[1] += widths[S[i]-'a'];
            else ans[1] = widths[S[i]-'a'],ans[0]++;
        }
        return ans;
    }
};