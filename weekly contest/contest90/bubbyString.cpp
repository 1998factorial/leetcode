class Solution {
public:
    int n,m;
    bool buddyStrings(string A, string B) {
        n = A.size(), m = B.size();
        if(n != m)return false;
        bool same = true;
        for(int i = 0; i < n; i++)
            if(A[i] != B[i])same = false;
        vector<int> cnta(26),cntb(26);
        for(int i = 0; i < n; i++)
            cnta[A[i]-'a']++,cntb[B[i]-'a']++;
        for(int i = 0; i < 26; i++)
            if(cnta[i] != cntb[i])return false;
        if(same){
            for(int i = 0; i < 26; i++)
                if(cnta[i] > 1)return true;
            return false;
        }
        //swap
        for(int i = 0; i < n; i++){
            if(A[i] != B[i]){
                int j = i;
                while(j < n && A[j] != B[i])j++;
                swap(A[i],A[j]);
                break;
            }
        }
        for(int i = 0; i < n; i++)
            if(A[i] != B[i]) return false;
        return true;
    }
};