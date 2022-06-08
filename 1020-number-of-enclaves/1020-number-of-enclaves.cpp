class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        int dir[5]={0,1,0,-1,0};
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            dfs(grid,i+dir[k],j+dir[k+1]);
        }
    }
        
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if((i*j==0 || i==grid.size()-1 || j==grid[0].size()-1) && grid[i][j]==1){
                    dfs(grid,i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};