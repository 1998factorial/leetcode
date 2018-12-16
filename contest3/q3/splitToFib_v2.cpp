class Solution {
public:
    bool check(string s, vector<int>& ans, int cur){
        int n = s.size();
        int m = ans.size();

        if(cur >= n and m >= 3)
            return true;

        int max_split = (s[cur] == '0') ? 1:10; // 0 or no restriction

        for(int i = 1; i <= max_split and cur + i <= n; i++){
            //try all possible positions
            long long num = 0;
            for(int j = 0; j < i; j++)num = num * 10 + (s[j+cur] - '0');
            if(num > (1LL << 31)-1)continue;
            if(m >= 2 and ans[m-1] + ans[m-2] != num)continue;
            ans.push_back(num);
            if(check(s,ans,cur+i))return true;
            ans.pop_back();
        }
        return false;
    }

    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        if(check(S,ans,0))
            return ans;
        return {};
    }
};