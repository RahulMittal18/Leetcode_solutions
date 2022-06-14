class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int m = word1.size();
        int n = word2.size();
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(word1[i-1]==word2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return m+n-2*dp[m][n];
    }
};