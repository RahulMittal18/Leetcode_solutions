class Solution {
public:
    
    int solve(int i,int j,string &s,string &p, int n,int m,vector<vector<int>> &dp){
        if(i==n || j==m){
            if(i==n) {
            for(int k=j;k<m;k++) if(p[k]!='*') return 0;
            return 1;
        }
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(s[i]==p[j] || p[j]=='?') return dp[i][j] = solve(i+1,j+1,s,p,n,m,dp);
        else if(p[j]=='*'){
            for(int k=i;k<=n;k++)
            ans|= solve(k,j+1,s,p,n,m,dp);
        }
        else return dp[i][j]=0;
        return dp[i][j]=ans;
    }
    
    bool isMatch(string s, string p) {
        int n= s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(0,0,s,p,n,m,dp);
    }
};