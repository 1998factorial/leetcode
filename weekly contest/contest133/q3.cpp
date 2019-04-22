//prefix sum array
class Solution {
public:
    int n;
    int s1[1001],s2[1001];
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        n = A.size();
        int ret=-(1<<30);
        memset(s1,0,sizeof(s1));memset(s2,0,sizeof(s2));
        for(int i=0;i<L;i++)s1[0]+=A[i];
        for(int i=1;i<=n-L;i++)s1[i]=s1[i-1]+A[i+L-1]-A[i-1];
        for(int i=0;i<M;i++)s2[0]+=A[i];
        for(int i=1;i<=n-M;i++)s2[i]=s2[i-1]+A[i+M-1]-A[i-1];
        for(int i=0;i<=n-L;i++){
            for(int j=0;j+M-1<i;j++){
                ret=max(ret,s1[i]+s2[j]);
            }
            for(int j=i+L;j<=n-M;j++){
                ret=max(ret,s1[i]+s2[j]);
            }
        }
        return ret;
    }
};