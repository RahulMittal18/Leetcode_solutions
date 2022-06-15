class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& grid,int i,int j,queue<pair<int,int>> &q){
        grid[i][j]=-1;
        int dir[5]={0,1,0,-1,0};
        for(int k=0;k<4;k++){
            int x = i + dir[k];
            int y = j + dir[k+1];
            if(x>=0 and y>=0 and x<m and y<n){
                if(grid[x][y]==1)
                dfs(grid,x,y,q);
                else if(grid[x][y]==0)
                    q.push({i,j});

            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = m;
        queue<pair<int,int>> q;
        int flag=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {
                    if(!flag){
                        flag=1;
                        dfs(grid,i,j,q);
                    }
                }
            }
        }
        
        int i,j;
        int dir[5]={0,1,0,-1,0};
        int d =0;
        while(!q.empty()){

            int nn = q.size();
            while(nn--){
                tie(i,j) = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x = i+dir[k];
                    int y = j+dir[k+1];
                    if(x>=0 and y>=0 and x<m and y<n){
                        if(grid[x][y]==1)
                            return d;
                        else if(grid[x][y]==0){
                            q.push({x,y});
                            grid[x][y]=-1;
                        }
                    }
                }
            }
            d++;
        }
        return 0;
    }
};