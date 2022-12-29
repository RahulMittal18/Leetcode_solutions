class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=1;
        dp[0][1]=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]) dp[i][0]=max(dp[i][0],1+dp[j][1]);
                else if(nums[i]<nums[j]) dp[i][1]=max(dp[i][1],1+dp[j][0]);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans=max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};