class Solution {
public:
    int ans=0;
    set<pair<int,int>> st;
    void dfs(vector<int> adj[],vector<int> &vis,int node){
        
        vis[node]=1;
        
        for(auto x: adj[node])
        {
            if(vis[x]==0){
                dfs(adj,vis,x);
                if(st.find({node,x})!=st.end()) ans+=1;
            }
           
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
       
        vector<int> adj[n];
        
        for(auto x: connections){
            st.insert({x[0],x[1]});
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(n,0);
        dfs(adj,vis,0);
        
        
        return ans;
    }
};