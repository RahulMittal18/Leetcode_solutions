class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0};
        int col[9][9]={0};
        int sub[9][9]={0};
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                //if(board[i][j]=='.') continue;
                if(board[i][j]!='.'){
                    int digit = board[i][j] - '0';
                    int sub_index = (i/3)*3+(j/3);
                    if(row[i][digit-1]==0 && col[j][digit-1]==0 && sub[sub_index][digit-1]==0){
                        row[i][digit-1] = 1;
                        col[j][digit-1] = 1;
                        sub[sub_index][digit-1] = 1;
                    }
                    else
                        return false;
                }
                //else return false;
            }
        }
        return true;
    }
};