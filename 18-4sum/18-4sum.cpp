class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
	
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
        vector<vector<int>> res;
        
        // If we have run out of numbers to add, return res.
        if (start == nums.size()) return res;
        
        // There are k remaining values to add to the sum. The 
        // average of these values is at least target / k.
        int average_value = target / k;
        
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest 
        // value in nums is smaller than target / k.
        if (nums[start] > average_value || average_value > nums.back()) return res;
            
        if (k == 2) return twoSum(nums, target, start);
    
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for(vector<int>& subset : kSum(nums, target-nums[i], i+1, k-1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), subset.begin(), subset.end());
                }
            }
        }                                   
        return res;
    }
	
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
        vector<vector<int>> res;
        int lo = start, hi = nums.size() - 1;
    
        while(lo < hi){
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            }
            else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            }
            else {
                res.push_back({ nums[lo++], nums[hi--] });
            }
        }                                                   
        return res;
    }
};