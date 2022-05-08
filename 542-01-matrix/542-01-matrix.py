class Solution(object):
    def updateMatrix(self, matrix):
        n=len(matrix) #rows
        m = len(matrix[0]) # columns
        dp=[[float("inf")]*m for _ in range(n)]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j]==1:
                    if i>0:
                        dp[i][j]=min(dp[i][j],1+dp[i-1][j])
                    if j>0:
                        dp[i][j]=min(dp[i][j],1+dp[i][j-1])
                else:
                    dp[i][j]=0

        for i in range(len(matrix)-1,-1,-1):
            for j in range(len(matrix[0])-1,-1,-1):
                if matrix[i][j]==1:                        
                    if j<m-1:
                        dp[i][j]=min(dp[i][j],1+dp[i][j+1])
                    if i<n-1:
                        dp[i][j]=min(dp[i][j],1+dp[i+1][j])
                else:
                    dp[i][j]=0
        return dp