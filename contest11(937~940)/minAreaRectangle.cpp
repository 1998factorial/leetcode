class Solution {
public:
    int minAreaRect(vector<vector<int>>& p) {
        set<pair<int,int>> s;
        int ans = 1 << 25,n = p.size();
        for(int i = 0; i < n; i++)s.insert({p[i][0],p[i][1]});
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(p[i][0] < p[j][0] && p[i][1] < p[j][1] && s.find({p[i][0],p[j][1]}) != s.end() && s.find({p[j][0],p[i][1]}) != s.end())ans = min(ans,(p[j][0]-p[i][0])*(p[j][1]-p[i][1]));
        if(ans == 1 << 25)return 0;
        return ans;
        //find returns an iterator
    }
};