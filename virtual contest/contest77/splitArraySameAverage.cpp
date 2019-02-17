//q805
//solution 1 : dfs + early exit
class Solution {
public:
    bool dfs(int i, int sumN, int N, vector<int>& A) {
        int n = A.size();
        if(N == 0) return sumN == 0;
        if(A[i] > sumN/N) return false;
        for(int j = i; j < n - N + 1; ++j) {
            if(j > i && A[j] == A[j-1]) continue;
            if(dfs(j+1,sumN-A[j],N-1,A)) return true;
        }
        return false;
    }
    bool splitArraySameAverage(vector<int>& A) {
        int n =A.size(), sum = 0;
        for(auto c : A) sum += c;
        sort(A.begin(),A.end());
        for(int len = 1; len <= n/2; ++len) {
            if(sum * len % n ) continue;
            if(dfs(0,sum*len/n,len,A)) return true;
        }
        return false;
    }
};

//solution 2 dp
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        //A_sum/k = sum/n = B_sum/(n-k) => sum*k/n is integer
        int n = A.size(), m = n/2, sum = 0;
        for(int num : A)sum += num;
        bool canK = false;
        for(int k = 1; k <= m && !canK; k++)
            if(sum*k % n == 0)canK = true;
        if(!canK)return false;
        vector<set<int>> dp(m+1);
        dp[0].insert(0);//initial condition
        for(int i = 0; i < n; i++)
            for(int len = m; len > 0; len--)
                for(const int j : dp[len-1])
                    dp[len].insert(A[i]+j);
        for(int k = 1; k <= m; k++)
            if(sum*k % n == 0 && dp[k].find(sum*k/n) != dp[k].end())return true;
        return false;
    }
};