class Solution {
public:
    int n;
    int videoStitching(vector<vector<int>>& c, int T) {
        n = c.size();
        sort(c.begin(),c.end(),[&](vector<int> a, vector<int> b){
            if(a[0] < b[0])return true;
            else if(a[0] == b[0] && a[1] < b[1])return true;
            return false;
        });
        int ret = 0;
        int cur = 0;
        for(int i = 0; i < n; i++){
            int nex = cur;
            while(i < n && c[i][0] <= cur)nex = max(nex,c[i][1]),i++;
            if(nex > cur)i--;
            ret++;
            cur = nex;
            if(nex >= T)break;
        }
        if(cur < T)return -1;
        return ret;
    }
};