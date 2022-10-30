class Solution {
public:       
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 1e4;
        queue<vector<int>> q;
        vector<vector<int>> vis(m,vector<int>(n,-1));
        if(grid[0][0]==1) k--;
        q.push({0,0,k,0});
        int dirs[5]={0,1,0,-1,0};
        while(!q.empty()){
            int nn = q.size();
            for(int jj=0;jj<nn;jj++){
                vector<int> v = q.front();
                q.pop();
                int i = v[0];
                int j = v[1];
                int kk = v[2];
                int steps = v[3];
                if(i==m-1 && j==n-1) return steps;

                if(i<0 || j<0 || i>=m || j>=n || (vis[i][j]!=-1 && vis[i][j]>=kk)) continue;
                
                if(grid[i][j]==1) {
                    if(kk>0) kk--;
                    else continue;
                }
                
                vis[i][j]=kk;
                for(int g=0;g<4;g++){
                    int x = i+dirs[g];
                    int y = j+dirs[g+1];
                    q.push({x,y,kk,1+steps});
                }
            }
        }
        return -1;
    }
};