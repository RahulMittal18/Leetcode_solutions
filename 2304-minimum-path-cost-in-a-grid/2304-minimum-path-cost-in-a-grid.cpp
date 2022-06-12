class Solution {
public:
    int dp[51][50];
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int i,int j,int n,int m){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n-1) {
            return grid[i][j];
        }
        dp[i][j] = INT_MAX;
        for(int k=0;k<m;k++){
            dp[i][j]=min(dp[i][j],grid[i][j]+moveCost[grid[i][j]][k]+solve(grid,moveCost,i+1,k,n,m));
        }
        return dp[i][j];
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        memset(dp,-1,sizeof dp);
        int ans = INT_MAX;
        for(int i=0;i<grid[0].size();i++){
            ans=min(ans,solve(grid,moveCost,0,i,grid.size(),grid[0].size()));
        }
        return ans;
    }
};