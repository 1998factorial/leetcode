//sort A
//and the rest is easy
class Solution{
public:
	int sumSubseqWidths(vector<int>& A) {
		sort(A.begin(),A.end());
		long sum = 0, mod = 1000000000 + 7, diff = 0;
		for(int i = 0; i < A.size(); i++){
			for(int j = i-1; j >= 0; j--){
				diff = A[i] - A[j];
				sum += diff * pow(2,i-j-1);
			}
		}
		return sum % mod;
	}
};
