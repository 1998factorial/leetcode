//A[0]<=..A[i]<=...A[n]
//A[i] larger than i numbers ,so we plus A[i]*2^i
//A[i] less than n-i-1 numbers, so we subtract A[i]*2^(n-i-1)
class Solution{
public:
	int sumSubseqWidths(vector<int> A) {
		sort(A.begin(),A.end());
		long x = 1, m = 1e9+7, result = 0;
		for(int i = 0; i < A.size(); i++, x = (x << 1) % m)
			result = (result + x*(A[i] - A[A.size()-i-1])) % m;
		return (result + m) % m; //to make result positive
	}
};