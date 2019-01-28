class Solution {
public:
    
    bool allCap(string w, int n){
        for(int i = 0; i < n; i++)
            if(w[i] < 'A' || w[i] > 'Z')return false;
        return true;
    }
    
    bool allLow(string w, int n){
        for(int i = 0; i < n; i++)
            if(w[i] < 'a' || w[i] > 'z')return false;
        return true;
    }
    
    bool check(string w, int n){
        if(w[0] < 'A' || w[0] > 'Z')return false;
        for(int i = 1; i < n; i++)
            if(w[i] < 'a' || w[i] > 'z')return false;
        return true;
    }
    
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n < 2)return allCap(word,n) || allLow(word,n);
        return allCap(word,n) || allLow(word,n) || check(word,n);
    }
};