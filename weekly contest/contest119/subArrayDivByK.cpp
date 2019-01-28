class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n = a.size(), ans = 0;
        vector<int> sum(n,0);
        vector<int> v(k,0);
        sum[0] = ((a[0] % k) + k) % k;
        ++v[sum[0]];
        for(int i = 1; i < n; i++){
            sum[i] = (((sum[i-1] + a[i]) % k) + k) % k;
            ++v[sum[i]];
        }
        for(int i = 0; i < k; i++){
            ans += v[i]*(v[i]-1)/2;
        }
        return ans+v[0];
    }
};