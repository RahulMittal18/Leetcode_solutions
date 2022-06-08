class Solution {
public:
    bool dfs(vector<vector<int>>& grid2,vector<vector<int>>& grid1,int i,int j){
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size() || grid2[i][j]==0)
            return true;
        bool e = grid2[i][j]==grid1[i][j];
        grid2[i][j]=0;
        bool a = dfs(grid2,grid1,i+1,j);
        bool b = dfs(grid2,grid1,i,j+1);
        bool c = dfs(grid2,grid1,i-1,j);
        bool d = dfs(grid2,grid1,i,j-1);
        return a&&b&&c&&d&&e;
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j]==1 && dfs(grid2,grid1,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};