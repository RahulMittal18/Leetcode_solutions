class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    dp[i][j]=matrix[i][j];
                }
                else{
                    int temp = 1e6;
                    temp = min(temp,matrix[i][j]+dp[i-1][j]);
                    if(j>0) temp = min(temp,matrix[i][j]+dp[i-1][j-1]);
                    if(j<m-1) temp = min(temp,matrix[i][j]+dp[i-1][j+1]);
                    dp[i][j] = temp;
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};