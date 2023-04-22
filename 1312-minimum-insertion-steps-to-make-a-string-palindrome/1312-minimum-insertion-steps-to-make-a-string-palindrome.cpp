class Solution {
public:
    int dp[501][501];
    int solve(int i,string &s,int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 0;
        if(s[i]==s[j]){
            ans = solve(i+1,s,j-1);
        }
        else{
            ans = 1 + min(solve(i+1,s,j),solve(i,s,j-1));
        }
        return dp[i][j] = ans;
    }
    
    
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        return solve(0,s,n-1);
    }
};