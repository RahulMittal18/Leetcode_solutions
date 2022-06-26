class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size()-k;
        int r = 0;
        int sum=0;
        int total = accumulate(nums.begin(),nums.end(),0);
        while(r<n){
            sum+=nums[r];
            r++;
        }
        int ans = sum;
        int i = 0;
        while(r<nums.size()){
            sum-=nums[i];
            sum+=nums[r];
            r++;
            i++;
            ans = min(ans,sum);
        }        
        return total-ans;
    }
};