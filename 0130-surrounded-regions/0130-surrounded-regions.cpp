class Solution {
public:
    
    void bfs2(vector<vector<char>>&board, int i, int j, int m, int n){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!='O') return;
        board[i][j]='C';
        bfs2(board,i-1,j,m,n);
        bfs2(board,i,j-1,m,n);
        bfs2(board,i+1,j,m,n);
        bfs2(board,i,j+1,m,n);
    }
    
    void solve(vector<vector<char>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]=='O'){
                bfs2(grid,i,0,m,n);
            }
        }
        
        for(int i=0;i<m;i++){
            if(grid[i][n-1]=='O'){
                bfs2(grid,i,n-1,m,n);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]=='O'){
                bfs2(grid,0,i,m,n);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[m-1][i]=='O'){
                bfs2(grid,m-1,i,m,n);
            }
        }

       
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
                else if(grid[i][j]=='C') grid[i][j]='O';
            }
        }
        
        
        

    }
};