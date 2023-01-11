class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i+1][j+1]+=(mat[i][j]+dp[i][j+1]+dp[i+1][j]-dp[i][j]);                
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x = i-k;
                int y = j-k;
                mat[i][j]=dp[min(n,i+k+1)][min(m,j+k+1)];
                if(x>=0) mat[i][j]-=dp[x][min(m,j+k+1)];
                if(y>=0) mat[i][j]-=dp[min(n,i+k+1)][y];
                if(x>=0 && y>=0) mat[i][j]+=dp[max(0,i-k)][max(0,j-k)];
            }
        }
        
        return mat;
    }
};