class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> dp[n+1];
        int ans = 2;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int d = nums[i]-nums[j];
                int cnt=1;
                if(dp[j].find(d)!=dp[j].end()){ 
                    cnt=dp[j][d];
                }
                dp[i][d]=1+cnt;
                ans = max(ans,dp[i][d]);
            }   
        }
        return ans;
    }
};