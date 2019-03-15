class RLEIterator {
public:
    RLEIterator(vector<int> A) {
        cur = 0;
        res = 0;
        N = 0;
        int k = A.size();
        for(int i = 0; i < k; i++){
            if(i % 2)continue;
            if(!A[i])continue;
            vector<long long> t(2);
            t[0] = A[i];
            t[1] = A[i+1];
            N++;
            mp.push_back(t);
        }
    }
    
    int next(int n) {
        res += n;
        while(cur < N && res > mp[cur][0])res -= mp[cur][0],cur++,cout << cur << endl;        
        if(cur < N)return mp[cur][1];
        return -1;
    }
    long long cur;
    long long res;
    int N;
    vector<vector<long long >> mp;//t[i][0] = interval, t[i][1] = val
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */