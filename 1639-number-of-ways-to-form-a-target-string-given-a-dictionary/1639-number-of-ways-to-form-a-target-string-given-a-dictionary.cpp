class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,vector<vector<int>>&freq,int j,string &target){
        if(j==target.size()) return 1;
        if(i==freq.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mod = 1e9+7;
        long long ans = 0;
        
        ans= (ans + (freq[i][target[j]-'a']*1ll*solve(i+1,freq,j+1,target))%mod)%mod;
        ans = (ans + solve(i+1,freq,j,target)) % mod;
        return dp[i][j] = ans%mod;
    }
      
    int numWays(vector<string>& words, string target) {
        int m = words[0].size();
        int n = target.size();
        int p = words.size();
        vector<vector<int>> freq(m,vector<int>(26,0));
        for(auto x:words){
            for(int j=0;j<x.size();j++){
                freq[j][x[j]-'a']++;
            }
        }
        dp.resize(m+1,vector<int>(n+1,-1));
        return solve(0,freq,0,target);
    }
};