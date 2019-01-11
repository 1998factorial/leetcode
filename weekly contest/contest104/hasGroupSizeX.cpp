class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> v(10000);
        int n = deck.size();
        int m = 100000;
        
        for(int i = 0; i < n; i++)
            ++v[deck[i]];
        
        for(int i = 0; i < 10000; i++)
            if(v[i])
                m = min(m,v[i]);
        
        if(m < 2)return false;
        
        int i = 2;
        
        while(i <= m){
            bool f = true;
            for(int j = 0; j < 10000; j++){
                if(v[j])
                    if(v[j] % i != 0){
                        f = false;
                        break;
                    }
            }
            if(f)return true;
            ++i;
        }
        return false;
    }
};