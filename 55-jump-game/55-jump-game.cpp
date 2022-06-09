class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int range = 0;
        while(i<n){
            if(i>range) return false;
            range = max(range,i+nums[i]);
            i++;
        }
        return true;
    }
};