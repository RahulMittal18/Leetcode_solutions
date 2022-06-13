class Solution {
public:
    int n,dp[202][202];
    int solve(vector<vector<int>>& t,int i,int j){
        if(i==n-1) return t[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]= t[i][j] + min(solve(t,i+1,j),solve(t,i+1,j+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        memset(dp, -1, sizeof dp);
        return solve(triangle,0,0);
    }
};