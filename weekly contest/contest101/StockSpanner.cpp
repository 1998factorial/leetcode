class StockSpanner {
public:
    StockSpanner() {
        n = 0;
        a.clear();
    }
    
    int next(int price) {
        int ret = 0;
        if(!n){
            n++;
            a.push_back(price);
            return ret+1;
        }
        int len = 0;
        for(int i = n-1; i >= 0; i--){
            if(a[i] > price){
                ret = max(ret,len);
                len = 0;
                break;
            }
            else{
                len++;
            }
        }
        ret = max(ret,len);
        a.push_back(price);
        n++;
        return ret+1;
    }
    vector<int> a;
    int n;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */