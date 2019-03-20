int sum[50001];
class Solution {
public:
    int n;
    int shipWithinDays(vector<int>& w, int D) {
        n = w.size();
        int l = w[0], r = 0;
        sum[0] = w[0];
        for(int i = 1; i < n; i++)
            sum[i] = sum[i-1] + w[i],l = max(l,w[i]);
        r = sum[n-1]; //maximal possible weights required
        while(l < r){
            int mid = (r+l)/2;
            int d = 0,i = 0;
            while(i < n){
                int j = i+1;
                while(j < n && sum[j]-sum[i]+w[i] <= mid)j++;
                d++,i = j;
            }
            if(d > D)l = mid+1; //need more
            else r = mid;
        }
        return l;
    }
};