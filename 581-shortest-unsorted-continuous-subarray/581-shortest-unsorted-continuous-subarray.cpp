class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v=nums;
        sort(v.begin(),v.end());
        if(nums==v)
            return 0;
        
        int l=0,r=nums.size()-1;
        while(v[l]==nums[l]) l++;
        while(v[r]==nums[r]) r--;
        return r-l+1;
    }
};