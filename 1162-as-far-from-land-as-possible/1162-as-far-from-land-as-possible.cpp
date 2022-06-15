class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        int dir[5]={0,1,0,-1,0};
        
        while(!q.empty()){
            pair<int,int> f = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int x = f.first + dir[i];
                int y = f.second + dir[i+1];
                if(x>=0 and y>=0 and x<m and y<n and grid[x][y]==0){
                    q.push({x,y});
                    grid[x][y]=grid[f.first][f.second]+1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,grid[i][j]);
            }
        }
        return ans==1?-1:ans-1;
    }
};