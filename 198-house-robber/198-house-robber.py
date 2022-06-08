class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]==-1){
            dp[i]=max(solve(nums,i+1,dp),nums[i]+solve(nums,i+2,dp));
        }
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(101,-1);
        return solve(nums,0,dp);
    }
};