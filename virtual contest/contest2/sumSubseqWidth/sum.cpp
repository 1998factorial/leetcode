//not efficient
//O(n*2^n)
//excceeded time limit
class Solution {
public:
	void gen(vector<int>& A, int& sum, vector<bool>& v, int index){
		if(index == A.size()){
			int mx = -100000, mn = 100000;
			bool empty = true;
			for(int j = 0; j < A.size(); j++){
				if(v[j]){
					empty = false;
					mx = max(A[j],mx);
					mn = min(A[j],mn);
				}
			}
			if(!empty){
				sum += (mx-mn);
				sum = sum % (1000000000 + 7);
			}
			return;
		}
		for(int i = index; i < A.size(); i++){
			v[i] = true;
			gen(A,sum,v,i+1);
			v[i] = false;
		}
		int mx = -100000, mn = 100000;
		bool empty = true;
		for(int j = 0; j < A.size(); j++){
			if(v[j]){
				empty = false;
				mx = max(A[j],mx);
				mn = min(A[j],mn);
			}
		}
		if(!empty){
			sum += (mx-mn);
			sum = sum % (1000000000 + 7);
		}
		return;
	}

    int sumSubseqWidths(vector<int>& A) {
        int sum = 0;
        vector<bool> v(A.size(),false);
        gen(A,sum,v,0);
        return sum;
    }
};