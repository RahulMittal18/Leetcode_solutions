class Solution {
public:
        void moveZeroes(vector<int>& nums) {
            int i=-1,j=0;
            while(j<nums.size()){
                if(nums[j]!=0){
                    i++;
                    swap(nums[i],nums[j]);
                }
                j++;
            }
        }

};