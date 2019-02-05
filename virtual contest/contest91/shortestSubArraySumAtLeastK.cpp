class Solution {
public:
	//a sliding window technique
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        int ans = n+1;
        vector<int> sum(n+1);
        for(int i = 0; i < n; i++)sum[i+1] = sum[i] + A[i];
        //sum[i] = A[0]+...+A[i-1]
        //for each i, find minimal j st sum[j]-sum[i] >= K
        deque<int> d;
        for(int i = 0; i < n+1; i++){
        	while(d.size() > 0 && sum[i]-sum[d.front()] >= K)
        		ans = min(ans,i-d.front()),d.pop_front();
        	//we have found minimal i for j(d.front()), so we drop j
			while(d.size() > 0 && sum[i] <= sum[d.back()])
				d.pop_back();
			//as if there exist k st sum[k]-sum[d.back()] <= K
			//and sum[d.back()] >= sum[i], then sum[k]-sum[i] <= K
			//and clearly, k-i is a better solution than k-d.back()
			//thus we can pop out d.back()
        	d.push_back(i);
        }
        return ans <= n ? ans : -1;
    }
};