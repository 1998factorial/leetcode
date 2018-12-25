class Solution {
public:
//still a really slow solution
	bool isPrime(int N){
		if(N == 1)return false;
		if(N == 2 or N == 3)return true;
		//primes in forms of 6n+1 or 6n-1
        if(N % 2 == 0 or N % 3 == 0)return false;
		for(int i = 5; i <= sqrt(N); i += 6){
			if((N % i == 0)or(N % (i+2) == 0))return false; //6k-1,6k+1
		}//check all primes less than sqrt(N)
		return true;
	}

	int reverse(int N){
		int M = 0;
		while(N){ //flip
			M = M*10 + N%10;
			N /= 10;
		}
        return M;
	}

	bool isP(int N){
		return N == reverse(N);
	}

    int primePalindrome(int N) {
        if(N>=1e7 and N<=1e8)
             return 100030001;
        if(N == 1)return 2;
        if(N == 2)return 2;
        if(N == 3)return 3;
        if(N == 5)return 5;
        while(!isP(N) or !isPrime(N)){
        	++N;
        }return N;
    }
};