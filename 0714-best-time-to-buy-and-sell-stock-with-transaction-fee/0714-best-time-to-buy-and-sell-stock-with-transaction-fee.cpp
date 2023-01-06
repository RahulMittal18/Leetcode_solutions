class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = -prices[0];
        int prev_buy = 0;
        int sell = 0;
        int prev_sell=0;
        for(int i=0;i<n;i++){
            prev_buy = buy;
            buy = max(prev_buy,sell-prices[i]);
            prev_sell = sell;
            sell = max(prev_sell, buy+prices[i]-fee);
        }
        return sell;
    }
};