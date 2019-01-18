class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        int ans = 0,n = t.size();
        int i = 0, j = n-1;
        if(n == 1){
            if(p >= t[0])return 1;
            else return 0;
        }
        sort(t.begin(),t.end());
         while(i <= j){   
            while(i <= j && p >= t[i]) p -= t[i],++i,++ans; //use power to get as many points as possible
            if(i < j){ //get largest power if we have points
                if(ans){
                    --ans,p += t[j],--j;
                }
                else return ans; //no points
            }
            if(i == j){ //last bit
                if(p >= t[i]) ++ans; 
                break;
            }
         }
        return ans;
    }
};

// a more concise one

class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        int n = t.size(),ans = 0;
        if(!n)return 0;
        sort(t.begin(),t.end());
        int i = 0,j = n-1;
        while(i <= j){
            if(p < t[i] && ans){
                --ans,p += t[j--];
            }
            if(p < t[i])break;
            p -= t[i++],++ans;
        }
        return ans;
    }
};