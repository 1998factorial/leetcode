class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    	int n = seats.size(),ans = 0;
    	for(int i = 0; i < n; i++){
    		if(seats[i])continue;
    		int left = 0, right = 0, j = i;
    		while(j >= 0 && !seats[j])++left,--j;
    		j = i;
    		while(j < n && !seats[j])++right,++j;
    		if(i == 0)
    			ans = max(ans,right);
    		else if(i == n-1)
    			ans = max(ans,left);
    		else 
    			ans = max(ans,min(left,right));
    	}
    	return ans;
    }
};