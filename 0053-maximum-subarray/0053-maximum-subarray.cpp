class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            curr = max(0,curr+nums[i]);
            ans=max(ans,curr);
        }
        return ans!=0?ans:*max_element(nums.begin(),nums.end());
    }
};