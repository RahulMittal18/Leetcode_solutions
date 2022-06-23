class Solution {
public:

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n =nums.size();
        int dp[n+1];
        memset(dp,0, sizeof dp);
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]) dp[i]=dp[i-1]+1;
            else dp[i]=0;
        }
        int ans =0;
        for(int i=0;i<n;i++) ans+=dp[i];
        return ans;
    }
};