class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long right_sum = 0;
        long left_sum = 0;
        for(auto x:nums) right_sum += x;
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            left_sum += nums[i];
            right_sum -= nums[i];
            int x = (left_sum/(i+1));
            int y = 0;
            if(right_sum!=0) y = (right_sum/(n-i-1));
            ans[i] = abs(x- y);
        }
        int res = 0;
        for(int i=1;i<n;i++){
            if(ans[res]>ans[i]) res = i;
        }
        return res;
    }
};