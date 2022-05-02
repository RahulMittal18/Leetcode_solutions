class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int l=0,r=nums.size();
        int n=nums.size();
        while(l<r){
            int mid = l + (r-l)/2;
            if(mid>=nums[mid])
                r=mid;
            else
                l=mid+1;
        }
        if(l<n and l==nums[l])
        return -1;
        return l;
        
    }
};