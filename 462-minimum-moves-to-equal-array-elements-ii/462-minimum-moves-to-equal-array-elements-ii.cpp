class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        if(n&1){
            int med = n/2;
            for(int x:nums){
                ans+=abs(nums[med]-x);
            }
        }
        else{
            int med1 = n/2;
            int med2 = n/2 -1;
            int a1 = 0;
            for(int x:nums){
                a1+=abs(nums[med1]-x);
            }
            int a2 = 0;
            for(int x:nums){
                a2+=abs(nums[med2]-x);
            }
            ans=min(a1,a2);
        }
        return ans;
    }
};