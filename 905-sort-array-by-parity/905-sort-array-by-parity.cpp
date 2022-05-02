class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[r]%2 < nums[l]%2){
                swap(nums[l],nums[r]);
                l++;
                r--;
            }
            if(nums[l]%2==0)
                l++;
            if(nums[r]%2==1)
                r--;
        }
        return nums;
    }
};