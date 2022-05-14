class Solution {
public:
    void dfs(int src, vector<pair<int,int>> edges[],vector<int>& vis,int temp,int& ans){
        if(temp>=vis[src]) return;
        vis[src]=temp;
        for(auto adj:edges[src]){
                dfs(adj.first,edges,vis,temp+adj.second,ans);
        }
    }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> edges[n];
        for(auto x:times){
            edges[x[0]-1].push_back({x[1]-1,x[2]});
        }
         for (int i = 0; i < n; i++) {
            sort(edges[i].begin(), edges[i].end());
        }
        vector<int> vis(n,1e8);
        int ans=INT_MIN;
        int temp=0;
        dfs(k-1,edges,vis,temp,ans);
        for(auto x: vis){
            ans=max(ans,x);
        }
        return ans==1e8 ? -1 : ans;
    }
};