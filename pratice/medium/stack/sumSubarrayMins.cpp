/*
a = [1,7,5,2,4,3,9]
subarray ends at 0	1
subarray ends at 1	1+7
subarray ends at 2	1+5+5
subarray ends at 3	1+2+2+2
subarray ends at 4	1+2+2+2+4
...
for each round, if a[j] is smaller than some val, replace them with a[j], and
increment count of a[j].
*/
typedef long long int64;

struct state{
	int val,count;
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int64 mod = 1e9+7;
        int ans = 0, n = a.size();
        stack<state> s;
        int64 stack_sum = 0; //accumulated sum for each round
        for(int i = 0; i < n; i++){
        	state j = {a[i],1};
        	while(!s.empty() && s.top().val > a[i]){
        		//replace s.top() by j
        		state t = s.top();
        		j.count += t.count;
        		stack_sum -= t.val * t.count;
        		s.pop();
        	}
        	s.push(j);
        	stack_sum += j.val * j.count;
        	stack_sum %= mod;
        	ans += stack_sum;
        	ans %= mod;
        }
        return (ans + mod) % mod;
    }
};