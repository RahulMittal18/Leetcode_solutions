class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        dp.resize(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i+1][j+1]+=(mat[i][j]+dp[i][j+1]+dp[i+1][j]-dp[i][j]);                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=0;
        res=dp[row2+1][col2+1];
        if(row1>=0) res-=dp[row1][col2+1];
        if(col1>=0) res-=dp[row2+1][col1];
        if(row1>=0 && col1>=0) res+=dp[row1][col1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */