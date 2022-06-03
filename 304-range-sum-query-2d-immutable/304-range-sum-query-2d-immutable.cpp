class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(j==0) dp.push_back({0});
                else if (i==0) dp.back().push_back(0);
                else dp.back().push_back(matrix[i-1][j-1]+dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]+dp[row1][col1]-dp[row2+1][col1]-dp[row1][col2+1];
        // return 0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */