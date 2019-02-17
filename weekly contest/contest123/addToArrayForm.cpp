class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
    	int n = A.size();
    	vector<int> ans;
    	int carry = 0;
    	for(int i = n-1; i >= 0; i--){
    		int r = K % 10;
    		A[i] += r + carry;
    		if(A[i] > 9)carry = 1;
    		else carry = 0;
    		A[i] %= 10;
    		K /= 10;
    	}
    	K += carry;
    	while(K){
    		A.insert(A.begin(),K % 10);
    		K /= 10;
    	}
    	return A;
	}
};