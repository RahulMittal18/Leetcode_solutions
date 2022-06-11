class Solution {
public:
   
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0) - x;
        if(sum < 0) return -1;
        if(sum == 0) return nums.size();
        int start = 0, cur = 0, len = -1;
        for(int end = 0; end < nums.size(); end++)
        {
            if (cur < sum)
                cur += nums[end];
            while (cur >= sum)
            {
                if (cur == sum)
                    len = max(len, end - start + 1);
                cur -= nums[start++];
            }
        }

        return len == -1 ? -1 : nums.size() - len;
    }
};