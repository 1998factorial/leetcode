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