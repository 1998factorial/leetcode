class Solution {
public:
    string baseNeg2(int N) {
        string ret = "";
        if(!N)return "0";
        while(N){
            int r = N % -2;
            N /= -2;
            if(r < 0){ //the key is to turn the remainder to positive
                r += 2,N++;
            }
            ret += '0'+r;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};