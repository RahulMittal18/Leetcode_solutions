class Solution {
public:
    vector<int> dp;

    int solve(int i,int pos,int target, int currFuel, vector<vector<int>>&stations){
        if(currFuel<0) return 502;
        if(i==stations.size()-1){
            if(currFuel>=target-pos) return 0;
            else if(currFuel+stations[i][1]>=target-pos) return 1;
            else return 502;
        }
        if(dp[i]!=-1) return dp[i];
        int not_filled = solve(i+1,stations[i+1][0],target,currFuel-(stations[i+1][0]-stations[i][0]),stations);
        int filled = 1 + solve(i+1,stations[i+1][0],target,currFuel-(stations[i+1][0]-stations[i][0])+stations[i][1],stations);
        return dp[i] = min(filled,not_filled);
    }
    
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        int ans=0,prev=0;
        priority_queue<int>pq;
        stations.push_back({target,INT_MAX});
        for(auto x:stations){
            startFuel-=(x[0]-prev);
            prev = x[0];
            while(pq.size()&& startFuel<0){
                startFuel+=pq.top();
                pq.pop();
                ans++;
            }
            if(startFuel<0) return -1;
            pq.push(x[1]);
        }
        return ans;
    }
};