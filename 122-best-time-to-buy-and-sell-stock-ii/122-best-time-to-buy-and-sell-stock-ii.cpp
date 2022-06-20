class Solution {
public:
    int n;
    
    // 1 for we have to buy now
    int solve(vector<int> &prices, int i, int buy,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        if(buy){
            dp[i][buy] = max(-prices[i]+solve(prices,i+1,0,dp), solve(prices,i+1,1,dp));
        }
        else{
            dp[i][buy] = max(prices[i]+solve(prices,i+1,1,dp), solve(prices,i+1,0,dp));
        }
        return dp[i][buy];
    }
    
    
    
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        if(n==1) return 0;

        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return solve(prices,0,1,dp);
    }
};