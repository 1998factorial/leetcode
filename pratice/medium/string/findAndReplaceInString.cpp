//Q833
//very annoying question
class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        string ans;
        vector<int> a(n);
        for(int i = 0; i < n; i++)a[i] = i;
        sort(a.begin(),a.end(),[&](int x,int y){
        	return indexes[x] < indexes[y]; //sort according to indexes
        });
    	int cur = 0;
    	for(int i = 0; i < n; i++){
    		int j = a[i];
    		int pos = indexes[j];
    		ans += s.substr(cur,pos-cur);
    		if(s.substr(pos,sources[j].size()) == sources[j]){
    			ans += targets[j];
    			cur = pos + sources[j].size();//skip 
    		}
    		else{
    			cur = pos;//can not skip
    		}
    	}
    	if(cur < s.size())ans += s.substr(cur);
    	return ans;
    }
};