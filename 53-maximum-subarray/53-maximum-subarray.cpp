class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans= nums[0];
        int currSum=0;
        for(int i=0;i<nums.size();i++){

            if(currSum<0)
                currSum=0;
            currSum+=nums[i];
            ans = max(currSum,ans);
            
        }
        return ans;
    }
};