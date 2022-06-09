class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int range = 0;
        while(i<nums.size()){
            if(i>range) return false;
            range = max(range,i+nums[i]);
            i++;
        }
        return true;
    }
};