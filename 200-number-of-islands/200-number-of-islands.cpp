class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int dir[5] = {0,1,0,-1,0};
        int islands =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    islands++;
                    grid[i][j]='0';
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> f = q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int r = f.first + dir[k];
                            int c = f.second + dir[k+1];
                            if(r>=0 and r<rows and c>=0 and c<cols and grid[r][c]=='1'){
                                grid[r][c]='0';
                                q.push({r,c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};