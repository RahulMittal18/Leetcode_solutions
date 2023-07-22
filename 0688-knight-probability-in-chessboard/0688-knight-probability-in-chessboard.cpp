class Solution {
public:
    double dp[26][26][101]; 
    double solve(int i,int j,int steps,int n){
        if(steps==0) return 1;
        if(dp[i][j][steps]!=-1) return dp[i][j][steps];
        vector<int> xs = {2,2,-2,-2,1,1,-1,-1};
        vector<int> ys = {1,-1,1,-1,2,-2,2,-2};
        double ans = 0;
        for(int k=0;k<8;k++){
            int newx = i+xs[k];
            int newy = j+ys[k];
            if(newx>=0 && newy>=0 && newy<n && newx<n){
                ans += solve(newx,newy,steps-1,n);
            }
        }
        return dp[i][j][steps] = ans;        
    }
    
    double knightProbability(int n, int k, int row, int column) {
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int l=0;l<101;l++){
                    dp[i][j][l]=-1;
                }
            }
        }
        double fav = solve(row,column,k,n);
        double res = fav;
        for(int i=0;i<k;i++){
            res/=8;
        }   
        return res;
    }
};