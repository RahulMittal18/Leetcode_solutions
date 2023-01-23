class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        int x = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) continue;
            for(int j=i+1;j<n;j++){
                int two_sum = nums[i]+nums[j];
                auto xx = lower_bound(nums.begin()+j,nums.end(),two_sum);
                int x = xx-(nums.begin()+j);
                if(xx==nums.end()) ans+=(n-j-1);
                else{
                    int val = *xx;
                    ans+=x;
                    if(val>=two_sum) ans--;
                }
            }
        }
        return ans;
    }
};