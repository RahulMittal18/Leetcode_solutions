class Solution {
public:
    
    bool solve(int i,int j,string &s,string &p,vector<vector<int>> &dp,char prev){
        if(i==-1 || j==-1){
            if(i==-1) {
                for(int k=j;k>=0;k-=2) if(p[k]!='*') return false;
            return true;
        }
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(prev!='-') if(prev==s[i] || prev=='.') return dp[i][j]= (solve(i-1,j,s,p,dp,prev) || solve(i,j-2,s,p,dp,'-'));
            else dp[i][j]=solve(i,j-2,s,p,dp,'-');
        if(s[i]==p[j] || p[j]=='.') return dp[i][j] = solve(i-1,j-1,s,p,dp,prev);
        else if(p[j]=='*'){
            if(p[j-1]==s[i])
                return dp[i][j]= (solve(i-1,j,s,p,dp,p[j-1]) || solve(i,j-2,s,p,dp,'-')) ;
            else if(p[j-1]=='.')
                return dp[i][j]= (solve(i-1,j,s,p,dp,p[j-1]) || solve(i,j-2,s,p,dp,'-')) ;
            else return dp[i][j]= solve(i,j-2,s,p,dp,'-');
                
        }
        else return dp[i][j]=false;
    }
    
    bool isMatch(string s, string p) {
        int n= s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(n-1,m-1,s,p,dp,'-');
    }
};