class Solution {
public:
    
    bool solve(int i,int n,string &s, set<string> &dict, vector<int> &dp){
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        dp[i]=0;
        for(int k=i;k<n;k++){
            if(dict.count(s.substr(i,k-i+1))==1){
                if(solve(k+1,n,s,dict,dp)) dp[i]=1;
            }
        }
        return dp[i];
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        int n  = s.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,s,dict,dp);
    }
};