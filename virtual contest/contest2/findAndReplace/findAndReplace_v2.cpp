//bijective idea

class Solution {
public:
	bool check(string w, string p){
		int n = w.size();
		int m = p.size();
		//unordered_map<char, char> from; //w
		//unordered_map<char, char> to; //p
		map<char,char> from;
		map<char,char> to;
		if(m != n)return false;
		for(int i = 0; i < n; i++){
			if(!from.count(w[i]))
				from[w[i]] = p[i]; //map to p
			if(!to.count(p[i]))
				to[p[i]] = w[i];
			if(from[w[i]] != p[i] or to[p[i]] != w[i])
				return false;
		}
		return true;
	}


	vector<string> findAndReplacePattern(vector<string>& w, string p) {
		vector<string> ans;
		for(int i = 0; i < w.size(); i++)
			if(check(w[i],p))ans.push_back(w[i]);
		return ans;
	}
};