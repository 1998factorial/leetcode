class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int n = a.size();
        vector<int> b(n);
        for(int i = 0; i < n; i++)
            b[i] = a[i]*a[i];
        sort(b.begin(),b.end());
        return b;
    }
};