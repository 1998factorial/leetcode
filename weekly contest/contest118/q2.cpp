class Solution {
public:

	bool sorted(vector<int>& a){
		int n = a.size(),i = 0;
		for(; i < n-1; i++)
			if(a[i] > a[i+1])return false;
		return true;
	}

    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        int n = A.size();
        int m = n;
        if(sorted(A))return ans;
        //find max, put it to the head, then reverse the whole
       	for(; m >= 0 && !sorted(A); m--){
       		int mx = -100000;
       		int index = 0;
       		for(int i = 0; i < m; i++)
       			if(mx < A[i]){
       				mx = A[i];
       				index = i;
       			}
       		reverse(A.begin(),A.begin()+index+1);
       		reverse(A.begin(),A.begin()+m);
       		ans.push_back(index+1);
       		ans.push_back(m);
       	}
        return ans;
    }
};