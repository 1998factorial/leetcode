class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int ans = 0, n = a.size();
        vector<int> A(n,1),B(n,1);
        for(int i = n-2; i >= 0; i--){
            if(i % 2 == 0){
                if(a[i] > a[i+1]){
                    A[i] = 1+A[i+1];
                }
                else if(a[i] < a[i+1]){
                    B[i] = 1+B[i+1];
                }
            }else{
                if(a[i] > a[i+1]){
                    B[i] = 1+B[i+1];
                }
                else if(a[i] < a[i+1]){
                    A[i] = 1+A[i+1];
                }
            }
        }
        int p = *max_element(A.begin(),A.end());
        int q = *max_element(B.begin(),B.end());
        ans = max(p,q);
        return ans;
    }
};