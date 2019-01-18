/*
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
*/
class Solution {
public:

	bool ispre(string& a, string& b){ //T iff a is prefix of b
		if(a.size()>b.size())return false;
		for(int i = 0; i < a.size(); i++){
			if(a[i] != b[i])return false;
		}
		return true;
	}

    string replaceWords(vector<string>& d, string s) {
        string ans;
        //set<string> a; //all appeared words
        int n = d.size();
        if(!n)return ans;
        map<string,string> mp;
        sort(d.begin(),d.end(),cmp); //sort by length ->
        int pre = 0, cur = 0;
    	for(int i = 0; i < s.size(); i++){
    		if(s[i] == ' '){
    			string t = s.substr(pre,cur-pre);
	    		if(!mp.count(t)){
	    			int j = 0;
	    			for(; j < n; j++){
	    				if(ispre(d[j],t)){
	    					mp[t] = d[j];
	    					break;
	    				}
	    			}
	    			if(j == n)mp[t] = t;
	    		}
	    		ans += mp[t]+' ';
    			pre = cur+1;
    		}
    		++cur;
    	}
    	string t = s.substr(pre,cur-pre);
	    if(!mp.count(t)){
	    	int j = 0;
	    	for(; j < n; j++){
	    		if(ispre(d[j],t)){
	    			mp[t] = d[j];
	    			break;
	    		}
	    	}
	    	if(j == n)mp[t] = t;
	    }
	    ans += mp[t];
        return ans;
    }

    static bool cmp(string& a, string& b){
    	return a.size() < b.size();
    }

};







