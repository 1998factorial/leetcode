/*
i < j => A[i]+A[j] != 2*A[k] (no average between A[i] and A[j])
observe : 
1. even+odd != 2*A[k]
2. [1,3,2] + 1 = [2,4,3] still beautiful 
3. [1,3,2] * k = [k,3k,2k] still beautiful as k*(A[i]+A[j]) = 2*k*A[k]
4. [1,3,5] + [2,4,6] = [1,3,5,2,4,6] still beautiful
對於構造類型的題目，應該嘗試在array頭部或尾部insert，甚至是中間，但由於中間是O(n)故否決
於是我們嘗試將兩個subarray合併成一個array的想法，從beautiful array的性質本身入手。
a divide and conquer approach should come up
*/
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> ret;
        ret.push_back(1);
        if(N == 1)return ret;
        while(ret.size() < N){
            vector<int> a;
            for(int i : ret)a.push_back(i*2 - 1);
            for(int i : ret)a.push_back(i*2);
            ret = a;
        }
        vector<int> b;
        for(int i : ret)
            if(i <= N)b.push_back(i);   
        return b;
    }
};