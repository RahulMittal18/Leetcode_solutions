class Solution {
public:
    map<int,int> mp;
    int solve(int i,vector<int> &dp,int size){
        if(i>=size) return 0;
        if(dp[i]==-1){
            dp[i]=max(solve(i+1,dp,size),mp[i]*i+solve(i+2,dp,size));
        }
        return dp[i];
    }
    
    int rob(int i) {
        vector<int> dp(i,-1);
        return solve(0,dp,i);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        for(int x:nums) mp[x]++;
        return rob(10001);
    }
};