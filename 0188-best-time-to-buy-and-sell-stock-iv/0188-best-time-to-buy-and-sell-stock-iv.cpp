class Solution {
public:
    int solve(int i,int n,vector<int> &prices,int isSelling,int count,vector<vector<vector<int>>>&dp,int k){
        if(i==n){
            if(isSelling) return -1e7;
            return 0;
        }
        if(count==k) return 0;
        if(dp[i][count][isSelling]!=-1) return dp[i][count][isSelling];
        int ans = 0;
        if(!isSelling){
            ans = max(solve(i+1,n,prices,isSelling,count,dp,k),solve(i+1,n,prices,1,count,dp,k)-prices[i]);
        }
        else{
            ans = max(solve(i+1,n,prices,isSelling,count,dp,k),solve(i+1,n,prices,0,count+1,dp,k)+prices[i]);
        }
        return dp[i][count][isSelling] = ans;
    }
    
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(0,n,prices,0,0,dp,k);
    }
};