class Solution {
public:

	string check(vector<string>& list, string& q){
		string ret;
		int len = q.size();
		for(auto& word : list){ //case1
			if(q == word)return q;
		}
		for(auto& word : list){
			if(word.size() == len){
				
			}
		}
		return ret;
	}

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        int n = wordlist.size(), m = queries.size();
        for(int i = 0; i < m; i++){
        	string p = check(wordlist,queries[i]);
        	ans.push_back(p);
        }
        return ans;
    }
};