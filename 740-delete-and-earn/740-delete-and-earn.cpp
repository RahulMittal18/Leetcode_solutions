class Solution {
public:
    map<int,int> mp;
    int solve(int i,int n,vector<int>&arr,vector<int>&dp){
        if(i>=10001) return 0;
        if(dp[i]!=-1) return dp[i];
        
        return dp[i]=max(mp[i]*i+solve(i+2,n,arr,dp),solve(i+1,n,arr,dp));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        for(auto x:nums){
            mp[x]++;
        }
        vector<int> arr;
        for(auto k:mp){
            arr.push_back(k.first);
        }
        int n = arr.size();
        vector<int> dp(10001,-1);
        return solve(0,n,arr,dp);
    }
};