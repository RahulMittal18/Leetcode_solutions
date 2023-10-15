class Solution {
public:
    int dp[501][501];
    int mod = 1e9+7;
    int solve(int i,int steps,int n){
        if(i<0 || i==n) return 0;
        if(steps==0) return i==0;
        
        if(dp[i][steps]!=-1) return dp[i][steps];
        
        int c1=solve(i-1,steps-1,n);
        int c2=solve(i,steps-1,n);
        int c3=solve(i+1,steps-1,n);

        return dp[i][steps] = ((c1+c2)%mod+c3)%mod;     
    }
    
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return solve(0,steps,arrLen);
    }
};