class Solution {
public:
    int dp[100001][3];
    int solve(int i,int prev,int n,vector<int>&nums1, vector<int> &nums2){
        if(i>=n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int ans = 0;
        if(prev==0){
            int not_take = solve(i+1,0,n,nums1,nums2);
            int take1 = 1 + solve(i+1,1,n,nums1,nums2);
            int take2 = 1 + solve(i+1,2,n,nums1,nums2);
            ans = max({ans,not_take,take1,take2});
        }
        else if(prev==1){
            int take1=0;
            int take2=0;
            if(nums1[i]>=nums1[i-1]) take1 = 1 + solve(i+1,1,n,nums1,nums2);
            if(nums2[i]>=nums1[i-1]) take2 = 1 + solve(i+1,2,n,nums1,nums2);
            ans = max({ans, take1, take2});

        }
        else{
            int take1=0;
            int take2=0;
            if(nums1[i]>=nums2[i-1]) take1 = 1 + solve(i+1,1,n,nums1,nums2);
            if(nums2[i]>=nums2[i-1]) take2 = 1 + solve(i+1,2,n,nums1,nums2);
            ans = max({ans, take1, take2});
        }
        return dp[i][prev]=ans;
    }
    
    
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        memset(dp, -1, sizeof dp);
        return solve(0,0,n,nums1,nums2);
    }
};