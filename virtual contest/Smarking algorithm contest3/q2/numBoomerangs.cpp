class Solution {
public:
    
    bool check(pair<int, int>& x,pair<int, int>& y,pair<int, int>& z){
        return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second) == (x.first-z.first)*(x.first-z.first)+(x.second-z.second)*(x.second-z.second);
    }
    
    int numberOfBoomerangs(vector<pair<int, int>>& p) {
        int ans = 0, n = p.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == i)continue;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j)continue;
                    if(check(p[i],p[j],p[k]))++ans;
                }
            }
        }
        return ans;
    }
};