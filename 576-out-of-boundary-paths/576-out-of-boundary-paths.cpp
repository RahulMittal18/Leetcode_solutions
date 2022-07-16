typedef long long ll;
class Solution {
public:
    int mod = 1e9 + 7;
    int dp[51][51][51];
    int solve(int i,int j,int m,int n,int moves){
        if(moves==0 and (i<0 || j<0 || i==m || j==n)) return 1;
        if(moves==0 or (i<0 || j<0 || i==m || j==n)) return 0;

        if(dp[i][j][moves]!=-1){
            return dp[i][j][moves];
        }
        int dir[5]={0,-1,0,1,0};
        ll res = 0;
        for(int k=0;k<4;k++){
            int x = i+dir[k];
            int y = j+dir[k+1];
            res += solve(x,y,m,n,moves-1)%mod;         
        }
        return dp[i][j][moves]=res%mod;
    }
    
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        ll ans = 0;
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=maxMove;i++){
            ans += solve(startRow,startColumn,m,n,i)%mod;
            ans%=mod;
        }
        return ans;
    }
};