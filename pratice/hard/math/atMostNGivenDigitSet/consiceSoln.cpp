class Solution{
public:
	int atMostNGivenDigitSet(vector<string>& D, int N) {
    	string s = to_string(N);
    	int D_size = D.size(), s_size = s.size(), num = 0;
    	for(int i = 1; i < s_size; i++)
    		num += pow(D_size,i);
    	for(int i = 0; i < s_size; i++){
    		bool eqn = false;
    		for(string &d :D){
    			if(d[0] < s[i])
    				num += pow(D_size, s_size - i - 1);
    			else if(d[0] == s[i])
    				eqn = true;
    		}
    		if(!eqn)return num;
    	}
        return num+1; // N can be made by digits in D 
    }
};