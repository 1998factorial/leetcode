//union find
vector<int> u(26);
class Solution {
public:

	int find(int i){
		if(u[i] != i)u[i] = find(u[i]);
		return u[i];
	}

	void U(int i, int j){
		u[find(i)] = u[find(j)];
	}

    bool equationsPossible(vector<string>& e) {
    	for(int i = 0; i < 26; i++)u[i] = i;
    	for(string a : e){
    		if(a[1] == '!')continue;
    		int i = a[0]-'a', j = a[3]-'a';
    		U(i,j);
    	}
    	for(string a : e){
    		if(a[1] == '=')continue;
    		int i = a[0]-'a', j = a[3]-'a';
    		if(find(i) == find(j))return false;
    	}
    	return true;
    }
};