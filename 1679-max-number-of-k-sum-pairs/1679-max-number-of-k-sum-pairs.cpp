class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        int l=0;
        sort(nums.begin(),nums.end());
        int r= nums.size()-1;
        while(l<r){
            if(nums[r]+nums[l]==k){
                ans+=1;
                l++;
                r--;
            }
            else if(nums[r]+nums[l]>k){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};