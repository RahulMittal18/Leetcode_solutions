class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if((mid==0 || nums[mid]>nums[mid-1]) && (mid==n-1 || nums[mid]>nums[mid+1])) return mid;
            else if(mid<n-1 && nums[mid]<nums[mid+1]) l = mid+1;
            else h = mid-1;
        }
        return 0;
    }
};