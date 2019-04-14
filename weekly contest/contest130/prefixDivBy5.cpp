typedef long long int64;

int sum[30001];

class Solution {
public:
    int n;
    vector<bool> prefixesDivBy5(vector<int>& A) {
        n = A.size();
        vector<bool> ret(n);
        memset(sum,0,sizeof(sum));
        sum[0] = A[0];
        ret[0] = (sum[0] % 5 == 0);
        for(int i = 1; i < n; i++){
            sum[i] = (sum[i-1]*2 + A[i]) % 5;
            if(sum[i] % 5 == 0)ret[i] = true;
        }
        return ret;
    }
};