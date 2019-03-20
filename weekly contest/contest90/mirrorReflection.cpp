class Solution {
public:

	int gcd(int a, int b){
        if(a > b)swap(a,b);
        if(a == 0)return b;
        return gcd(a,b % a);
	}

    int mirrorReflection(int p, int q) {
        int lcm = p*q/gcd(p,q);
        if((lcm/q) % 2 == 0)
            return 2;
        if((lcm/p) % 2 == 0)
            return 0;
        return 1;
    }
};