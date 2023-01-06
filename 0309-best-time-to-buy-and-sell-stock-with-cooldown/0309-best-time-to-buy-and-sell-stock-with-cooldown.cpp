class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy[n+2],sell[n+2];
        int ans = 0;
        buy[0]=INT_MIN;
        buy[1]=INT_MIN;
        sell[0]=0;
        sell[1]=0;
        for(int i=0;i<n;i++){
            buy[i+2] = max(buy[i+1],sell[i]-prices[i]);
            sell[i+2] = max(buy[i+1]+prices[i],sell[i+1]);
            ans = max(ans,sell[i+2]);
        }
        return ans;
    }
};