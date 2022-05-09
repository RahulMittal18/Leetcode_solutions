class Solution {
public:
    bool solve(int src,vector<vector<int>>& graph,int color[]){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: graph[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int color[graph.size()];
        memset(color,-1,sizeof color);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!solve(i,graph,color)) return false;
            }
        }
        return true;
    }
};