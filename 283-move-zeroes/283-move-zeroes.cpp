class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        if(nums.size()<2){
            return ;
        }
        int r=1;
        int l=0;
        while(r<nums.size()){
            if(nums[l]!=0){
                l++;r++;
                continue;
            }
            if(nums[r]==0){
                r++;
                continue;
            }
            if(nums[l]==0 and nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;r++;
            }
            
            
        }
        // return nums;
    }
};