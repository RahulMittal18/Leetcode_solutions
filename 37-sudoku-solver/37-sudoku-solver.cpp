class Solution {
public:
    bool rec(vector<set<int>> &r,vector<set<int>> &c,vector<set<int>> &b,vector<vector<char>>& board,int i,int j){
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
                if(r[i].count(k)!=1 && c[j].count(k)!=1 && b[(i/3)*3 + j/3].count(k)!=1){
                    board[i][j]='0'+k;
                    r[i].insert(k);
                    c[j].insert(k);
                    b[(i/3)*3 + j/3].insert(k);
                    crct = rec(r,c,b,board,i,j+1);
                    if(crct==true){
                        return true;
                    }
                    r[i].erase(k);
                    c[j].erase(k);
                    b[(i/3)*3 + j/3].erase(k);
                    board[i][j]='.';
                }
            }
            return false;  
        }
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<set<int>> r(9),c(9),b(9);
        for(int i=0;i<9;i++){ 
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    r[i].insert(board[i][j]-'0');
                    c[j].insert(board[i][j]-'0');
                    b[(i/3)*3 + j/3].insert(board[i][j]-'0');
                }
                
            }
        }
        rec(r,c,b,board,0,0);
        
    }
};