class Solution {
public:
    int dp[10001][7][7];
    int mod = 1e9 +7;
    int solve(int n,map<int,vector<int>> &mp,int prev,int sec_prev){
        if(n==0) return 1;
        if(dp[n][prev][sec_prev]!=-1) return dp[n][prev][sec_prev];
        int temp = 0;
        for(int x:mp[prev]){
            if(x!=sec_prev){
                temp+=(solve(n-1,mp,x,prev))%mod;
                temp%=mod;
            }
        }
        dp[n][prev][sec_prev] = temp%mod;
        return dp[n][prev][sec_prev];
    }
    
    
    int distinctSequences(int n) {
        memset(dp,-1,sizeof dp);
        map<int,vector<int>> mp;
        mp[0]={1,2,3,4,5,6};
        mp[1]={2,3,4,5,6};
        mp[2]={1,3,5};
        mp[3]={1,2,4,5};
        mp[4]={1,3,5};
        mp[5]={1,2,3,4,6};
        mp[6]={1,5};
        return solve(n,mp,0,0);
    }
};