/*

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.

*/

//normalize to string then compare

class Solution {
public:
    string f(string a){
        unordered_map<char,int>mp;
        for(int i = 0; i < a.size(); i++)
            if(!mp.count(a[i]))mp[a[i]] = mp.size();
        
        for(int i = 0; i < a.size(); i++)
            a[i] = 'a' + mp[a[i]];
        return a;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto &w :words)
            if(f(w) == f(pattern))
                ans.push_back(w);
        return ans; 
    }
};