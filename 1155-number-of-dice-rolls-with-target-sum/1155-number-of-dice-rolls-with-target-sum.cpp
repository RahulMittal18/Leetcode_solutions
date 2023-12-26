class Solution {
public:
    int mod = 1e9+7;
    int dp[31][1001];
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<=target;i++){
            for(int j=0;j<=n;j++){
                for(int l=1;l<=k;l++){
                    if(j==0 && i==0) dp[j][i]=1;
                    else{
                        if(l<=i && j>0)
                        dp[j][i] = (dp[j][i]+dp[j-1][i-l])%mod;
                    }
                }
            }
        }
    return dp[n][target];
    }
};