class Solution {
public:
    int findMinMoves(vector<int>& m) {
        int ans = 0, n = m.size();
        if(!n || n == 1)return 0;
        vector<int> sum(n);
        sum[n-1] = m[n-1];
        for(int i = n-2; i >= 0; i--)
            sum[i] = sum[i+1] + m[i];
        if(sum[0] % n != 0)return -1; // impossible
        int t = sum[0]/n;
        for(int i = 0; i < n; i++){
            int steps = 0;
            if(!i || i == n-1)steps = abs(m[i] - t); //flow through m[i]
            else{
                int l = t*(i)-sum[0]+sum[i], r = t*(n-1-i)-sum[i+1]; //left flow and right flow
                if(l >= 0 && r >= 0)steps = abs(r) + abs(l) //left & right underflow
                else steps = max(abs(r),abs(l));
            }
            ans = max(ans,steps);
        }
        return ans;
    }
};