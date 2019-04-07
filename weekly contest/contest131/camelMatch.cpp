class Solution {
public:
    int n;
    
    bool canMatch(string a, string b){ //(q[i],pat)
        int len_a = a.size(), len_b = b.size();
        int i = 0, j = 0;
        for(; i < len_a; i++){
            if(j < len_b && a[i] == b[j])j++;
            else{
                if(a[i] >= 'A' && a[i] <= 'Z')return false;
            }
        }
        return j == len_b;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        n = queries.size();
        if(!n)return {};
        vector<bool> ret(n);
        for(int i = 0; i < n; i++){
            ret[i] = canMatch(queries[i],pattern);
        }
        return ret;
    }
};