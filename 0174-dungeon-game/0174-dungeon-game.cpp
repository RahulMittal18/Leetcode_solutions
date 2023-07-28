class Solution {
public:
    bool check(int x,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]+x<=0) return false;
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = grid[0][0]+x;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                dp[i][j] = -1e7;
                if(i>0){
                    dp[i][j] = max(dp[i][j],dp[i-1][j]+grid[i][j]);
                }
                if(j>0){
                    dp[i][j] = max(dp[i][j],dp[i][j-1]+grid[i][j]);
                }
                if(dp[i][j]<=0) dp[i][j] = -1e7;

            }
        }
        return dp[n-1][m-1]>0;
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int l =1;
        int r =400001;
        int ans = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(mid,dungeon)){
                ans = mid;
                r = mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};