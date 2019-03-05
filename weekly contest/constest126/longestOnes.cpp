class Solution {
public:
    int longestOnes(vector<int>& a, int K) {
        int ans = 0, n = a.size();
        int i = 0;
        for(; i < n; i++){
            int j = i,k = K;
            while(j < n){
                if(a[j])j++;
                else{
                    if(k > 0)k--,j++;
                    else break;
                }
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};

//problem translate to "find the longest subarray with at most K zeros"
//a[i..j] has <= k zeros, j++
//a[i..j] has > k zeros, i++
class Solution {
public:
    int longestOnes(vector<int>& a, int K) {
        int ans = 0, n = a.size();
        int i = 0;
        for(int j = 0; j < n; j++){
            K -= a[j] == 0; //if a[j] is 0, K--
            if(K < 0 && a[i++] == 0)K++; //K < 0, i++, if old(a[i]) is 0, K++
            ans = max(ans,j-i+1); 
        }
        return ans;
    }
};