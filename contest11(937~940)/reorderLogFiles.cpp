class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        //get letters
        int len = logs.size();
        for(int i = 0; i < len; i++){
            int j = 0;
            while(j < logs[i].size() && logs[i][j] != ' ')++j;
            ++j;
            if(isalpha(logs[i][j]))ans.push_back(logs[i]);
        }
        //sort
        sort();
        //get digits
        for(int i = 0; i < len; i++){
            int j = 0;
            while(j < logs[i].size() && logs[i][j] != ' ')++j;
            ++j;
            if(isdigit(logs[i][j]))ans.push_back(logs[i]);
        }        
        return ans;
    }
};