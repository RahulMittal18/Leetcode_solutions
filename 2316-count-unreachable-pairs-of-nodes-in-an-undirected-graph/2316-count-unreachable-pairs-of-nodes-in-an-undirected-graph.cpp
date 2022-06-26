class Solution {
public:
    
    void dfs(vector<vector<int>>&graph,int src,vector<bool>&vis,long long int &count){
        vis[src]=true;
        count++;
        for(auto nei: graph[src]){
            if(!vis[nei]) dfs(graph,nei,vis,count);
        }
    }
    
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long int ans = 0;
        vector<bool> vis(n,false);
        vector<vector<int>> graph(n);
        for(auto x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            long long int count = 0;
            if(!vis[i]) dfs(graph,i,vis,count);
            ans+=(count*(n-count));
        }
        return ans/2;
    }
};