/*
This is a really cool solution by cuiaoxiang
key idea: if there exists a solution, then there must exist the first 2 fib numbers
by trying all possible first 2 numbers and count the number of fib numbers that we
can generate, we can quickly generate our solutions.
真不愧为ACM选手
*/
typedef long long int64;
class Solution {
public:

	int count(string s, int k, int64 x, int64 y){
		int n = s.size(),ret = 2;
		while(k < n){
			int64 z = x+y;
			if(z > (1LL << 31)-1)return 0;
			if(s[k] == '0' && z != 0)return 0;
			int64 sum = s[k]-'0';
			++k;
			for(; k < n && sum < z; k++)sum = sum*10 + (s[k]-'0');
			if(sum != z)return 0;
			++ret;
			x = y;
			y = z;
		}
		return ret;
	}

    vector<int> splitIntoFibonacci(string s) {
        int n = s.size();
        for(int i = 1; i <= 10 && i < n; i++ ){
        	if(s[0] == '0' && i > 1)continue;
        	for(int j = 1; j <= 10 && i+j < n; j++){
        		if(s[i] == '0' && j > 1)continue;
        		int64 x = 0, y = 0;
        		for(int u = 0; u < i; u++)x = x*10 + (s[u] - '0');
        		for(int u = 0; u < j; u++)y = y*10 + (s[u+i] - '0');
        		if(x > (1LL << 31)-1 || y > (1LL << 31)-1)continue;
        		int m = count(s,i+j,x,y);
        		if(m < 2)continue;
        		vector<int> ans(m,0);
        		ans[0] = x;
        		ans[1] = y;
        		for(int u = 2; u < m; u++)ans[u] = ans[u-1] + ans[u-2];
        		return ans;	
        	}
        }
        return {};
    }
};