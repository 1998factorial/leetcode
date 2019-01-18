//Q967
//Input: N = 3, K = 7
//Output: [181,292,707,818,929]

class Solution {
public:

	void f(int i, int n, int k, vector<int>& ans,int num){
        num = num * 10 + i;
		if(n == 1){
			ans.push_back(num);
			return;
		}
		//num = num*10;
		if(i < 10){
			if(i+k < 10)f(i+k,n-1,k,ans,num);
			if(i-k >= 0 && k != 0)f(i-k,n-1,k,ans,num);
		}
	}

    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if(N == 1){
            for(int i = 0; i < 10; i++)ans.push_back(i);
            return ans;
        }
        for(int i = 1; i < 10; i++){
        	f(i,N,K,ans,0);
        }
        return ans;
    }
};