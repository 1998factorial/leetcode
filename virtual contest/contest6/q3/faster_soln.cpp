class Solution {
public:
    int primePalindrome(int N) {
        
        if (N < 100)
        {
            for (int i = N; ; ++i)
            {
                if (IsPrime(i) == true)
                {
                    vector<int> vec;
                    GetDigits(i, vec);
                    if (IsPalin(vec) == true) return i;
                }
            }
        }
        else
        {
            for (int i = N; ; ++i)
            {
                if (IsPrime(i) == true)
                {
                    vector<int> vec;
                    GetDigits(i, vec);
                    if (vec.size() % 2 == 0)
                    {
                        i = pow(10, vec.size());                        
                        continue;
                    }
                    
                    if (IsPalin(vec) == true) return i;
                }
            }
        }
    }
    
    bool IsPalin(vector<int>& vec)
    {
        if (vec.size() == 1) return true;
        
        int i = 0;
        int j = vec.size() - 1;
        
        while (i < j)
        {
            if (vec[i] != vec[j]) return false;
            ++i;
            --j;
        }
        
        return true;
    }
    
    void GetDigits(int n, vector<int>& vec)
    {
        while (n > 0)
        {
            vec.push_back(n % 10);
            n = n / 10;
        }
    }
    
    int IsPrime(int n)
    {
        if (n <= 1) return false;
        if (n <= 3) return true;
        
        if (n % 2 == 0) return false;
        if (n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0) return false;
        
        return true;
    }
};