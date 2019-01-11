class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
    	int len = s.size(),n = shifts.size();
    	string ans = s;
    	int sum = 0;
    	for(int i = n-1; i >= 0; i--){
    		sum += shifts[i];
    		sum = sum % 26;
    		int k = (ans[i] - 'a' + sum) % 26;
    		ans[i] = 'a' + k;
    	}
    	return ans;
    }
};