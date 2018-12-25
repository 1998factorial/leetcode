/*
Example:
Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.
*/
class Solution {
public:
    //heeellooo <--- hello, heeellooo <-x helo
    bool f(string s, string word){
        int i = 0,j = 0;
        while(i < s.size() && j < word.size()){
        	int count_i = 0, count_j = 0;
        	char c = s[i];
        	while(i < s.size() && s[i] == c){
                ++i,++count_i;
            }
        	while(j < word.size() && word[j] == c){
                ++j,++count_j;
            }
            if(count_i == count_j)continue;
        	if(count_i < count_j)return false;
        	if(count_i < 3)return false;
        }
        
        return i == s.size() && j == word.size();
    }
    
    int expressiveWords(string s, vector<string>& words) {
        int ret = 0;
        for(auto& word: words){
            ret += f(s,word);
        }
        return ret;
    }
};