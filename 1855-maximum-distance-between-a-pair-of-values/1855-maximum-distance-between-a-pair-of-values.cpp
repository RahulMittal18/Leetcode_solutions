class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=INT_MIN;
        for(int i=0;i<nums1.size();i++){
            int l=i,r=nums2.size()-1;
            int temp=-1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(nums2[mid]>=nums1[i]){
                    temp=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            ans=max(ans,temp-i);
        }
        return max(0,ans);
    }
};