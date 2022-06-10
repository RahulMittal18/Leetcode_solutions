// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    bool isSafe(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n) {
      int x=row,y=col;
    //   Check for same row
      
        while(y>=0) {
            if(board[x][y]==1) {
                return false;
            }
            y--;
        }
        
        // Check for Upper Digonal
        
        x=row, y=col;
        while(x>=0 && y>=0) {
            if(board[x][y]==1) {
                return false;
            }
            x--,y--;
        }
        
        // Check for lower Digonal
        
        x=row, y=col;
        while(x<n && y>=0) {
            if(board[x][y]==1) {
                return false;
            }
            x++,y--;
        }
        
        
        return true;
    }
    
    
    void addans(vector<vector<int>>&ans,vector<vector<int>>&board) {
        vector<int>tans;
        int n=board.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                
                if(board[i][j]!=0)
                tans.push_back(j+1);
            }
        }
        
        ans.push_back(tans);
        
    }
    
    void solver(int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n) {
        if(col==n) { 
          addans(ans,board);
          return;
        }
        //  solve one case and recursion will take care
            for(int row=0;row<n;row++) {
                // Checking queen is safe is not
                if(isSafe(row,col,ans,board,n)) {
                    board[row][col]=1;
                    solver(col+1,ans,board,n);
                    // Backtracking
                    board[row][col]=0;
                }
            }
            
    }
    
public:
    vector<vector<int>> nQueen(int n) {
      vector<vector<int>>ans;
      vector<vector<int>>board(n,vector<int>(n,0));
      int src=0;
      
      solver(src,ans,board,n);
      
      sort(ans.begin(),ans.end());
      return ans;
      
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends