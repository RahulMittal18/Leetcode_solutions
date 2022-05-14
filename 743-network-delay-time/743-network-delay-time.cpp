class Solution {
public:
    void dij(int src, vector<pair<int,int>> edges[],vector<int>& vis){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, src});
        vis[src]=0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(curr.first > vis[curr.second]) continue;
            for(auto adj:edges[curr.second]){
                if(vis[adj.first]> curr.first + adj.second){
                    vis[adj.first] = curr.first + adj.second;
                    pq.push({vis[adj.first],adj.first});
                }
            }    
        }        
    } 
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> edges[n];
        for(auto x:times){
            edges[x[0]-1].push_back({x[1]-1,x[2]});
        }
        
        vector<int> vis(n,1e8);
        int ans=0;
        dij(k-1,edges,vis);
        for(auto x: vis){
            ans=max(ans,x);
        }
        return ans==1e8 ? -1 : ans;
    }
};