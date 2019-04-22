//dp
class Solution {
public:
    int dp[55][55];
    bool seen[55][55];
    vector<vector<int>> a;
    int n;
    int solve(int i, int n1, int n2){
        if(i>=n)return 0;
        if(seen[n1][n2])return dp[n1][n2];
        int ret=1<<30;
        if(n1==n/2){
            ret=a[i][0]+solve(i+1,n1,n2+1);
        }
        else if(n2==n/2){
            ret=a[i][1]+solve(i+1,n1+1,n2);
        }
        else{
            ret=min(a[i][0]+solve(i+1,n1,n2+1),a[i][1]+solve(i+1,n1+1,n2));
        }
        seen[n1][n2]=true;
        return dp[n1][n2]=ret;
    }
    
    int twoCitySchedCost(vector<vector<int>>& A) {
        int ret=1<<30;
        a=A;
        n=a.size();
        memset(dp,0,sizeof(dp));
        memset(seen,false,sizeof(seen));
        ret=solve(0,0,0);
        return ret;
    }
};