class Solution {
public:

   int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> job;
        int n = startTime.size();
        for(int i=0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(job.begin(),job.end());
        
        map<int,int> mp;
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int start = job[i][0];
            int profit = job[i][2];
            int end = job[i][1];
            auto it = mp.lower_bound(end);
            dp[i]=max(dp[i+1],job[i][2]+(*it).second);
            mp[start]=dp[i];
        }
        
        return dp[0];
    }
};