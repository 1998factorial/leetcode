class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ans;
        while(A > 0 && B > 0){
            if(A > B){
                ans += "aab";
                A -= 2, B--;
            }
            else if(A < B){
                ans += "bba";
                B -= 2, A--;
            }
            else{
                ans += "ab";
                A--,B--;
            }
        }
        if(A > 0){
            while(A > 0)ans += "a", A--;
        }
        if(B > 0){
            while(B > 0)ans += "b", B--;
        }
        return ans;
    }
};