class Solution {
public:
    int solve(vector<int>& nums,int i,int dp[]){
        if(i>=nums.size()) return 0;
        if(dp[i]==-1){
            dp[i]=max(solve(nums,i+1,dp),nums[i]+solve(nums,i+2,dp));
        }
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        memset(dp,-1,sizeof dp);
        return solve(nums,0,dp);
    }
};