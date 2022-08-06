class Solution {
public:
    
    void dfs(vector<int>&edges,int src,vector<int> &vis,vector<int> &res,int n){
        vis[src]=1;
        if((edges[src]!=-1 and vis[edges[src]]==-1)) {
            res[edges[src]] = 1 + res[src];    
            dfs(edges,edges[src],vis,res,n);
        }
    }
    
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> res(2,vector<int> (n,-1));
        res[0][node1]=0;
        res[1][node2]=0;
        vector<int> vis1(n,-1);
        dfs(edges,node1,vis1,res[0],n);
        vector<int> vis2(n,-1);
        dfs(edges,node2,vis2,res[1],n);
        int ans = n+1;
        int mn = n+1;

        for(int i=n-1;i>=0;i--){
            if(res[0][i]!=-1 and res[1][i]!=-1){
                if(max(res[0][i],res[1][i])<=mn){
                    ans = i;
                    mn = max(res[0][i],res[1][i]);
                }
            }
        }
        return ans==n+1 ? -1 : ans;
    }
};