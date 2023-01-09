class Solution:
    def getRow(self, rowIndex):
        
        dp = [[1]*(rowIndex+1) for i in range(rowIndex+1)]
                
        for i in range(1,rowIndex+1):
            for j in range(1,rowIndex+1):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
                
        li=[]
        
        i=rowIndex
        j=0
        
        while i>=0 and j<=rowIndex:
            li.append(dp[i][j])
            i-=1
            j+=1
            
        return(li)