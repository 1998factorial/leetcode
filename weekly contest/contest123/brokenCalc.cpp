//X = 1024, Y = 1 => 1023
//X = 2, Y = 3 => 2->4->3 => 2
//X *= 2 or X -= 1
class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X >= Y)return X-Y;
        int ans = 0;
        //if Y % 2 == 0, pre(Y) = Y/2 
        //else, pre(Y) = Y+1
        while(Y != X){
        	if(Y % 2 == 0) Y /= 2, ans++;
        	else Y++, ans++;
        }
        return ans+X-Y;
    }
};