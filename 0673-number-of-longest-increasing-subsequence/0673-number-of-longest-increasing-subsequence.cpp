class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1,1);
        vector<int> count(n+1,1);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]) {
                    if(1 + dp[j] > dp[i]){
                        dp[i] = 1 + dp[j];
                        count[i] = 0;
                    }
                    if(1 + dp[j] == dp[i]){
                        count[i] += count[j];
                    }
                }
            }
        }
        int x = *max_element(dp.begin(),dp.end());
        int ans = 0;
        for(int i=0;i<n;i++) ans = dp[i]==x?ans+count[i]:ans;
        return ans;
    }
};