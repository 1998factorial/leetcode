vector<string> t = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int ans = 0, n = words.size();
        if(!n)return 0;
        set<string> s;
        for(int i = 0; i < n; i++){
            string p = "";
            int m = words[i].size();
            for(int j = 0; j < m; j++){
                p += t[words[i][j]-'a'];
            }
            s.insert(p);
        }
        ans = s.size();
        return ans;
    }
};