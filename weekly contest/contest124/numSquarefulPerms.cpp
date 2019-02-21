/*
    1 <= len(A) <= 12
    1 <= A[i] <= 10^9
*/
typedef long long int64;
const int N = 12;
int dp[1 << N][N]; //dp[i][j] = "number of permuatations at state i given that the last element is A[j]"
bool sum[N][N]; //sum[i][j] is true iff A[i]+A[j] is perfect square
//O(n^2 * 2^n) time complexity
class Solution {
public:
    int n;

    bool isPerfectSquare(int64 m){
        int s = sqrt(m);
        return s*s == m;
    }

    int numSquarefulPerms(vector<int>& A) {
        n = A.size();
        sort(A.begin(),A.end());//avoid duplication
        int ans = 0;
        memset(dp,0,sizeof(dp)),memset(sum,false,sizeof(sum));
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                sum[i][j] = sum[j][i] = isPerfectSquare(A[i]+A[j]);
        for(int i = 0; i < n; i++)
            if(i == 0 || A[i] != A[i-1]) //record first for all distinct numbers
                dp[1 << i][i] = 1;
        for(int i = 0; i < (1 << n); i++){
            for(int j = 0; j < n; j++){
                if(!dp[i][j])continue; //(i,j) not reachable
                for(int k = 0; k < n; k++){
                    if((1 << k) & i)continue; //
                    if(!sum[j][k])continue;
                    if(k > 0 && !((1 << (k-1)) & i) && A[k] == A[k-1])continue;
                    dp[(1 << k)|i][k] += dp[i][j];
                }
            }
        }
        for(int i = 0; i < n; i++)
            ans += dp[(1 << n)-1][i];
        return ans;
    }
};