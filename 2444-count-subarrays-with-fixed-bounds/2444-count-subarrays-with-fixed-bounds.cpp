class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int l =0;
        int r= 0;
        long ans = 0;
        int lmin = 0;
        int lmax = 0;
        bool minf = false;
        bool maxf = false;
        while(r<n){
            if(nums[r]>maxK || nums[r]<minK){
                lmin=0;
                lmax=0;
                l=r+1;
            }
            if(nums[r]==minK){
                minf = true;
                lmin = r;
            }
            if(nums[r]==maxK){
                maxf = true;
                lmax = r;
            }
            if(minf && maxf){
                ans+=max(0,(min(lmin,lmax)-l+1));
            }
            r++;   
        }
         
        return ans;
    }
};