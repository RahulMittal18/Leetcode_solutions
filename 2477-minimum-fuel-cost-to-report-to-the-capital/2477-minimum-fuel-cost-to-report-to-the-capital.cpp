class Solution {
public:
    
    long long solve(int src, vector<vector<int>> &adj, vector<bool>&vis, int seats,long long &ans){
        vis[src]=true;
        long long nodes=1;
        for(auto nei:adj[src]){
            if(!vis[nei]) {
                nodes += (solve(nei,adj,vis,seats,ans));
                // cout<<nei<<" "<<nodes<<" "<<ans<<endl;
            }
        }
        if(src!=0) ans+=(nodes+seats-1)/seats;
        return nodes;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> adj(n+1);
        for(auto r:roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        long long ans = 0;
        vector<bool> vis(n+1,false);
        solve(0,adj,vis,seats,ans);
        return ans;
    }
};