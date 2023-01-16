class Solution {
public:
    int dp[505][505];
    
    int editDis(string& word1, string& word2, int n1, int n2)
    {
        if(n1 == 0)
            return n2;
        if(n2 == 0)
            return n1;
        if(dp[n1][n2] !=-1)
        {
            return dp[n1][n2];
        }
        if(word1[n1-1] == word2[n2-1]) {
            dp[n1][n2] = editDis(word1, word2, n1-1, n2-1);
            return dp[n1][n2];
        }
            
        dp[n1][n2]=  1+min(editDis(word1, word2, n1, n2-1),
                  min(editDis(word1, word2, n1-1, n2),
                  editDis(word1, word2, n1-1, n2-1)));
        return dp[n1][n2];
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        for(int i=0;i<=n1+1;i++)
        {
            for(int j=0;j<=n2+1;j++)
            {
                dp[i][j] = -1;
            }
        }
        dp[n1][n2] = editDis(word1, word2, n1, n2);
        return dp[n1][n2];
        
    }
};