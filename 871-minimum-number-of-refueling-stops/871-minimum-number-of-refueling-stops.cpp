class Solution {
public:    
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