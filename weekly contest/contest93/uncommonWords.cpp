class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> ans;
        int n = A.size(), m = B.size();
        map<string,int> cntA, cntB;
        int i = 0;
        while(i < n){
            string word = "";
            while(i < n && A[i] != ' ')word += A[i],i++; //split by spaces 
            cntA[word]++,i++;
        }
        i = 0;
        while(i < m){
            string word = "";
            while(i < m && B[i] != ' ')word += B[i],i++;
            cntB[word]++,i++;
        }
        for(auto& c : cntA){
            if(cntA[c.first] == 1 && !cntB[c.first])ans.push_back(c.first);
        }
        for(auto& c : cntB){
            if(cntB[c.first] == 1 && !cntA[c.first])ans.push_back(c.first);
        }
        return ans;
    }
};