class Solution {
public:  
    bool isSafe(int row,int col,vector<string> temp,int n,vector<bool> &rowQ,vector<bool> &upperDiag,vector<bool> &lowerDiag){
            if(rowQ[row] or upperDiag[row-col+n-1] or lowerDiag[row+col]) return false;        
        return true;
    }
    
    
    void solve(int col,vector<string> &temp,vector<vector<string>> &ans, int n,vector<bool> &rowQ,vector<bool> &upperDiag,vector<bool> &lowerDiag){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,temp,n,rowQ,upperDiag,lowerDiag)){
                temp[row][col]='Q';
                rowQ[row]=true;
                upperDiag[row-col+n-1]=true;
                lowerDiag[row+col]=true;
                solve(col+1,temp,ans,n,rowQ,upperDiag,lowerDiag);
                temp[row][col]='.';
                rowQ[row]=false;
                upperDiag[row-col+n-1]=false;
                lowerDiag[row+col]=false;
            }
        }
        
    }    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> vec(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            vec[i]=s;
        }
        vector<bool> rowQ(n,false);
        vector<bool> upperDiag(2*n-1,false);
        vector<bool> lowerDiag(2*n-1,false);
        solve(0,vec,ans,n,rowQ,upperDiag,lowerDiag);
        return ans;
    }
};