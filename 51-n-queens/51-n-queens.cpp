class Solution {
public:
    
    bool isSafe(int row,int col,vector<string> temp,int n){
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(temp[i][j]=='Q') return false;
        }
        
        for(int i=row,j=col;i<n && j>=0;i++,j--){
            if(temp[i][j]=='Q') return false;
        }
        
        for(int i=row,j=col;j>=0;j--){
            if(temp[i][j]=='Q') return false;
        }
        
        return true;
    }
    
    
    void solve(int col,vector<string> &temp,vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,temp,n)){
                temp[row][col]='Q';
                solve(col+1,temp,ans,n);
                temp[row][col]='.';
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
        solve(0,vec,ans,n);
        return ans;
    }
};