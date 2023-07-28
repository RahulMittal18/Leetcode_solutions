class Solution {
public:
        
    int memo[21][21];
    
    int maxDiff(vector<int>& nums, int left, int right, int n) {
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        if (left == right) {
            return nums[left];
        }
        
        int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right, n);
        int scoreByRight = nums[right] - maxDiff(nums, left, right - 1, n);
        memo[left][right] = max(scoreByLeft, scoreByRight);
        
        return memo[left][right];
    }
    
        bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < 21; ++i) {
            memset(memo[i],-1,sizeof(memo[i]));
        }
        
        return maxDiff(nums, 0, n - 1, n) >= 0;
    }
};