class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy[n+2],sell[n+2];
        int ans = 0;
        int prev_buy=INT_MIN;
        int prev_sell=0;
        int prev2_sell=0;
        for(int i=0;i<n;i++){
            prev_buy = max(prev_buy,prev2_sell-prices[i]);
            prev2_sell = prev_sell;
            prev_sell = max(prev_buy+prices[i],prev_sell);
            ans = max(ans,prev_sell);
        }
        return ans;
    }
};