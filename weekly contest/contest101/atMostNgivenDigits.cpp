typedef long long int64;
class Solution {
public:
    
    int helper(vector<string>& D, int N, int n){
        //{1,2,3,4,5,6} 33, [1,2][1-6]
        //[3][1-3]
        //{1,2,3,4,5,6} 11,[1][1]
        int m = N;
        int d = 1;
        while(m)
        {
            if(m < 10)break;
            m /= 10;
            d *= D.size();
        }
        int cnt = 0;
        int i = 0;
        for(; i < D.size() && D[i][0]-'0' < m; i++)cnt++;
        int ret = 0;
        ret += d * cnt;
        if(i < D.size() && D[i][0]-'0' == m){
            int ten = 1;
            int p = N;
            for(int j = 0; j < n-2; j++)p /= 10;
            if(p % 10 == 0)return ret;
            for(int k = 0; k < n-1; k++)ten *= 10;
            if(n > 1)ret += helper(D,N % ten,n-1);
            else ret++;
        }
        return ret;
    }
    
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        //cout << N << endl;
        if(N == 0)return 0;
        int num = 0, n = N, m = D.size();
        int a = 0; //most significant digit of N
        while(n){
            if(n < 10)a = n;
            num++;
            n /= 10;
        }
        //N has num digits
        int64 ret = 0, cnt = 1;
        for(int i = 1; i < num; i++)cnt *= m, ret += cnt;
        //now we handle the case where it has num digits
        int count = 0;
        //count # digits in D less than or eq to a
        bool hasA = false;
        int i = 0;
        for(; i < m && D[i][0]-'0' < a; i++)count++;
        if(count > 0)ret += (count)*cnt; //# * |D|^(num-1)
        //count with a.... follow by num-1 digits
        if(i < m && D[i][0]-'0' == a){
            if(num > 1){
                //211, {1,2,3,4,5,6}
                //2xx then xx can not be greater than 11
                //两位数由D生成且不大于11
                int ten = 1;
                int n = N;
                //if next digit is 0 continue
                for(int j = 0; j < num-2; j++)n /= 10;
                if(n % 10 == 0)return ret;
                for(int k = 0; k < num-1; k++)ten *= 10;
                ret += helper(D,N % ten,num-1);
            }
            else ret++;
        }
        return ret;
    }
};