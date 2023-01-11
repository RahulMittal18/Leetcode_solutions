class Solution {
public:
    int solve(vector<vector<int>>& adj,int src, vector<bool>& hasApple, vector<bool>& vis,int cost){
        if(vis[src]) return 0;
        vis[src]=true;
        int childrenCost = 0;        

        for(auto nei:adj[src]){
            childrenCost+=solve(adj,nei,hasApple,vis,2);        
        } 
        if(childrenCost==0 && !hasApple[src]) return 0;
        return childrenCost+cost;
    }
    
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,false);
        return solve(adj,0,hasApple,vis,0);
    }
};