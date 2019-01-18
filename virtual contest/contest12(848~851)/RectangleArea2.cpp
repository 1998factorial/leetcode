//TLE
typedef long long int64;
int64 mod = 1e9+7;
class Solution {
public:

	vector<int> intersect(vector<int>& a, vector<int>& b){

		return {max(a[0],b[0]),max(a[1],b[1]),min(a[2],b[2]),min(a[3],b[3])};
	}

	int area(vector<int>& a){
		return ((max(0,a[3]-a[1]) % mod) * (max(0,a[2]-a[0]) % mod) + mod) % mod;
	}

    int rectangleArea(vector<vector<int>>& a) {
        int64 ans = 0;
        int n = a.size();
        for(int i = 1; i < (1 << n); i++){
        	vector<int> rec = {0,0,1000000000,1000000000};
        	int sign = -1;
        	for(int j = 0; j < n; j++){
        		if(i & (1 << j)){
        			rec = intersect(rec,a[j]);
                    printf("%d,%d,%d,%d\n",rec[0],rec[1],rec[2],rec[3]);
        			sign *= -1;
        		}
        	}
        	ans += sign * area(rec);
        	ans = (ans + mod) % mod;
        }
        return ans;
    }
};

//

class Solution {
public:
	int rectangleArea(vector<vector<int>>& a) {

	}
};

