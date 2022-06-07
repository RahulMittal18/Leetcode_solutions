class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int dir[5] = {0,1,0,-1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int temp=0;
                    grid[i][j]=0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> f = q.front();
                        temp++;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int r = f.first + dir[k];
                            int c = f.second + dir[k+1];
                            if(r>=0 and r<m and c>=0 and c<n and grid[r][c]==1){
                                grid[r][c]=0;
                                q.push({r,c});
                            }
                        }
                    }
                    res=max(res,temp);
                }
            }
        }
        return res;
    }
};