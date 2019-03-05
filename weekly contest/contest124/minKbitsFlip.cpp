//Greedy
//if u see a 0, flip it
class Solution {
public:
    int minKBitFlips(vector<int>& a, int k) {
        int n = a.size(), ans = 0;
        vector<bool> f(n);
        for(int i = 0; i < n; i++){
            if(!a[i]){
                if(i+k > n)return -1;
                ++ans;
                for(int j = 0; j < k; j++)
                    a[i+j] = 1 - a[i+j];
            }            
        }
        return ans;
    }
};