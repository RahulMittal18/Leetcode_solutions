class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(int k : nums) mp[k]+=k;
        int mx = *max_element(nums.begin(),nums.end());
        int n = mp.size();
        int dp[mx+1];
        dp[0]=0;
        dp[1]=mp[1];
        for(int i=2;i<=mx;i++){
            dp[i] = max(mp[i]+dp[i-2],dp[i-1]);
        }
        return dp[mx];
    }
};