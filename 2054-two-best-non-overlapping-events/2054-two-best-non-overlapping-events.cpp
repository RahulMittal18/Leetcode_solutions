class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> job=events;
        int n = events.size();
        
        int ans = 0;
        sort(job.begin(),job.end());
        
        map<int,int> mp;
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int start = job[i][0];
            int profit = job[i][2];
            int end = job[i][1];
            auto it = mp.upper_bound(end);
            ans = max(ans,(*it).second+profit);
            dp[i]=max(dp[i+1],profit);
            mp[start]=max(mp[start],dp[i]);
        }
        
        return ans;
    }
};