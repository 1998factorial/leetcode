class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        set<int> s;
        int n = 0, m = 0;
        if(x == 1)n = 1;
        else if (x > 1)
            while(pow(x,n) <= bound)++n;
        if(y == 1)m = 1;
        else if (y > 1)
            while(pow(y,m) <= bound)++m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int r = pow(x,i) + pow(y,j);
                if(r <= bound && s.count(r) == 0)
                    s.insert(r);
            }
        }
        for(auto& e : s)
            ans.push_back(e);
        
        return ans;
    }
};