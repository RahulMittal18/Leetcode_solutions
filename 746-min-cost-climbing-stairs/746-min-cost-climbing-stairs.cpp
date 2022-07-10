class Solution {
public:
    
    int solve(vector<int> &costs,int i,int dp[]){
        if(i>=costs.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int op1 = solve(costs,i+1,dp);
        int op2 = solve(costs,i+2,dp);
        return dp[i]=costs[i]+min(op1,op2);
    }
    
    int minCostClimbingStairs(vector<int>& costs) {
        int n = costs.size();
        int dp[n];
        memset(dp,-1,sizeof dp);
        int a1 = solve(costs,0,dp);
        memset(dp,-1,sizeof dp);
        int a2 = solve(costs,1,dp);
        return min(a1,a2);
    }
};