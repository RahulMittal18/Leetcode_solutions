class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n = nums.size();
        int ans = 0;
        int x = 0;
        for(i;i<n;i++){
            if(nums[i]==0) continue;
            for(int j=i+1;j<n;j++){
                auto xx = lower_bound(nums.begin()+j,nums.end(),nums[i]+nums[j]);
                int x = xx-(nums.begin()+j);
                if(xx==nums.end()) ans+=(n-j-1);
                else{
                    int val = *xx;
                    ans+=x;
                    if(val>=nums[i]+nums[j]) ans--;
                }
            }
        }
        return ans<0?0:ans;
    }
};