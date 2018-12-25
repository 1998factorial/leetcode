class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        int n = s.size();
        for(int i = 0; i < n; i++){
        	int dist = 0,l = 0,r = 0;
        	bool left = false,right = false;
        	if(s[i] == c){
        		ans.push_back(0);
        		continue;
        	}
        	for(int j = i-1; j >= 0; j--){
        		++l;
        		if(s[j] == c){
        			left = true;
        			break;
        		}
        	}
        	for(int j = i+1; j < n; j++){
        		++r;
        		if(s[j] == c){
        			right = true;
        			break;
        		}
        	}
        	if(!left)dist = r;
        	else if(!right)dist = l;
        	else dist = min(r,l);	
        	ans.push_back(dist);
        }
        return ans;
    }
};