class Solution {
public:
    int jump(vector<int>& nums) {
        int i, j, index;
        vector<int> dp(nums.size(), 10000);
        dp[0]=0;            // to reach 1st index, jumps needed=0
        for(i=0; i<nums.size(); i++)
        {
            index=i+1;
            while(index<i+nums[i]+1)
            {
                if(index >= nums.size()) break;
                dp[index] = min(dp[index], dp[i]+1);
                index++;
            }
        }
        return dp[nums.size()-1];
    }
};