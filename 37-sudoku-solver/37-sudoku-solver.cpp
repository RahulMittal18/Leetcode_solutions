class Solution {
public:
    bool rec(vector<vector<int>> &r,vector<vector<int>> &c,vector<vector<int>> &b,vector<vector<char>>& board,int i,int j){
        if(j==9){
            if(i==8) return true;
            return rec(r,c,b,board,i+1,0);
        }
        if(board[i][j]!='.'){
            return rec(r,c,b,board,i,j+1);
        }
        else{
            bool crct = false;
            for(int k=1;k<=9;k++){
                if(r[i][k]==0 && c[j][k]==0 && b[(i/3)*3 + j/3][k]==0){
                    board[i][j]='0'+k;
                    r[i][k]=1;
                    c[j][k]=1;
                    b[(i/3)*3 + j/3][k]=1;
                    crct = rec(r,c,b,board,i,j+1);
                    if(crct==true){
                        return true;
                    }
                    r[i][k]=0;
                    c[j][k]=0;
                    b[(i/3)*3 + j/3][k]=0;
                    board[i][j]='.';
                }
            }
            return false;  
        }
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> r(10,vector<int> (10,0)),c(10,vector<int>(10,0)),b(10,vector<int>(10,0));
        for(int i=0;i<9;i++){ 
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    r[i][board[i][j]-'0']=1;
                    c[j][board[i][j]-'0']=1;
                    b[(i/3)*3 + j/3][board[i][j]-'0']=1;
                }
                
            }
        }
        rec(r,c,b,board,0,0);
        
    }
};