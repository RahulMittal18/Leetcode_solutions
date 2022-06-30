class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        int med = n/2;
        for(int x:nums){
            ans+=abs(nums[med]-x);
        }
        return ans;
    }
};