class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = -prices[0];
        int sell = 0;
        for(int i=0;i<n;i++){
            buy = max(buy,sell-prices[i]);
            sell = max(sell, buy+prices[i]-fee);
        }
        return sell;
    }
};