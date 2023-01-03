class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int minp = 1;
        int maxp = 1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                int x = minp;
                minp = min(nums[i],maxp*nums[i]);
                maxp = max(nums[i],x*nums[i]);
            }
            else{
                minp = min(nums[i],minp*nums[i]);
                maxp = max(nums[i],maxp*nums[i]);    
            }
            ans = max(ans,maxp);
        }
        return ans;
    }
};