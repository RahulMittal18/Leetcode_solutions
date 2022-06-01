class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int temp=nums[0];
        res.push_back(temp);
        for(int i=1;i<nums.size();i++){
            temp+=nums[i];
            res.push_back(temp);
        }
        return res;
    }
};