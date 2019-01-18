/*
["time", "me", "bell"], 
we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].
*/

class Solution {
public:

    bool isPrefix(string& a, string& b){ //b is prefix of a
        if(b.size() > a.size())return false;
        for(int i = 0; i < b.size(); i++){
            if(a[a.size()-b.size()+i] != b[i])return false;
        }return true;
    }


    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size(),ans = 0;
        sort(words.begin(),words.end(),cmp);
        for(int i = 0; i < n; i++){ 
            bool r = true;
            for(int j = 0; j < i; j++){ //if words[i] is prefix of words[j],then we dont include it
                if(isPrefix(words[j],words[i])){// is prefix
                    r = false;
                    break;
                }
            }
            if(r) ans += words[i].size() + 1;
        }       
        return ans;
    }
    static bool cmp(string& a, string& b){
        return a.size() > b.size();
    }
};