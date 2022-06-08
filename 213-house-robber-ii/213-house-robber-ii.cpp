class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums,int j,int i){
        if(i<j) return 0;
        if(dp[i]==-1){
            dp[i]=max(solve(nums,j,i-1),nums[i]+solve(nums,j,i-2));
        }
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        memset(dp, -1, sizeof(dp)); 
        int a = solve(nums,0,nums.size()-2);
        memset(dp, -1, sizeof(dp)); 
        int b = solve(nums,1,nums.size()-1);
        return max(a,b);
    }
};