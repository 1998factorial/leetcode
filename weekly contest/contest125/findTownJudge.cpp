class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n = trust.size();
        int cur = -1;
        map<int,int> mp,mq;
        for(int i = 0; i < n; i++){
            mp[trust[i][1]]++;//# trust [i][1]
            mq[trust[i][0]]++;//# [i][0] trust
        }
        if(N == 1 && !n)return 1;
        for(auto& m : mp){
            if(m.second == N-1 && !mq[m.first])return m.first;
        }
        return cur;
    }
};