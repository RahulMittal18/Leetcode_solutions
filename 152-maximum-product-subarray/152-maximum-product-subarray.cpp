class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minp = nums[0];
        int maxp = nums[0];
        int ans = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                int temp = minp;
                minp = maxp;
                maxp = temp;
            }
            minp = min(minp*nums[i],nums[i]);
            maxp = max(maxp*nums[i],nums[i]);
            ans = max(ans,maxp);
        }
        return ans;
    }
};