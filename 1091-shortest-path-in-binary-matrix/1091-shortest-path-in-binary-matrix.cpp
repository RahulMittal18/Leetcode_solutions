class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = 1;
        int row = grid.size();
        if (row == 0) return -1;
        int col = grid[0].size();
        if (col == 0 ) return -1;
        if (grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1;

        queue<pair<int, int>> q;
        q.push({0,0});
        vector<vector<int>>directions={{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,-1},{-1, 1}};
        grid[0][0] = 1;
        while(!q.empty()){
            auto curr = q.front();
            int x = curr.first, y = curr.second;
            if( x == row -1 && y == col -1) return grid[x][y];

            for(auto direction : directions){
                int nx = x + direction[0];
                int ny = y + direction[1];
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0){
                    q.push({nx,ny});
                    grid[nx][ny] = grid[x][y] + 1;
                }
            }
            q.pop();
        }
        return -1;
    }
};