class Solution {
public:
    int maxProfit(vector<int>& p) {
        //to find max(p[j] - p[i]) where j > i
        int n = p.size(),buy_price = 10000000,max_profit = 0;
        for(int i = 0; i < n; i++){
        	buy_price = min(buy_price,p[i]);
        	max_profit = max(max_profit,p[i]-buy_price);
        }
        return max_profit;
    }
};