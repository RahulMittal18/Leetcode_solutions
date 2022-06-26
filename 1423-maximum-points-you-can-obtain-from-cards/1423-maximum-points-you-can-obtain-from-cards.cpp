class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int r = n-1;
        int sum=0;
        int l=0;
        while(l<k){
            sum+=nums[l];
            l++;
        }
        l--;
        int ans = sum;
        while(l>=0){
            sum-=nums[l];
            sum+=nums[r];
            r--;
            l--;
            ans = max(ans,sum);
        }
        return ans;
    }
};