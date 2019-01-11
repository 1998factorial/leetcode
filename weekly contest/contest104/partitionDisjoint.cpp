class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int n = a.size(),ans = -1;
        vector<int> l(n);
        vector<int> r(n);
        l[0] = a[0];
        for(int i = 1; i < n; i++)
            l[i] = max(l[i-1],a[i]);
        r[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--)
            r[i] = min(r[i+1],a[i]);
        for(int i = 0; i < n-1; i++){
            if(l[i] <= r[i+1])return i+1;
        }
        return ans;
    }
};