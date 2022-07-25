class Solution {
public:
   int searchF(vector<int>& nums, int target) {
       int low = 0;
       int flag=-1;
        int high = nums.size()-1;
       while(low<=high){
           int mid = low + (high-low)/2;
           if(nums[mid]==target)
           {
               flag=mid;
               high=mid-1;
           }
           else if(nums[mid]>target)
                high=mid-1;
           else
               low=mid+1;
       }
       return flag;
   }
    
    int searchL(vector<int>& nums, int target) {
        int low = 0;
        int flag=-1;
        int high = nums.size()-1;
       while(low<=high){
           int mid = low + (high-low)/2;
           if(nums[mid]==target)
           {
               flag=mid;
               low=mid+1;
           }
           else if(nums[mid]>target)
                high=mid-1;
           else
               low=mid+1;
       }
        return flag;
   }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        int a1 = searchF(nums,target);
        int a2 = searchL(nums,target);
        return {a1,a2};
        
    }
};