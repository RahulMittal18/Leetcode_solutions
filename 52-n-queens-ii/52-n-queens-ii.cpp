class Solution {
public:
    
    void solve(int col,int n,vector<bool> &r, vector<bool> &ud,vector<bool> &ld,int &ans){
        if(col==n){
            ans++;
            return;
        }
        
        for(int row=0;row<n;row++){
            if(!(r[row] || ud[row-col+n-1] || ld[row+col])){
                r[row]=true;
                ud[row-col+n-1] = true;
                ld[row+col] = true;
                solve(col+1,n,r,ud,ld,ans);
                r[row]=false;
                ud[row-col+n-1] = false;
                ld[row+col] = false;
            }
        }
        
    }
    
    
    int totalNQueens(int n) {
        vector<bool> r(n,false);
        vector<bool> ud(2*n-1,false);
        vector<bool> ld(2*n-1,false);
        int ans=0;
        solve(0,n,r,ud,ld,ans);
        return ans;
    }
};