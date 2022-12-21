class Solution {
public:
    bool dfs(vector<vector<int>> &graph,int src,vector<int> &color,int c){
        if(color[src]!=-1) return color[src]==c;
        color[src]=c;
        for(auto nei: graph[src]){
            if(color[src]!=-1 && !dfs(graph,nei,color,1-c)) return false;
        }
        return true;
    }
    
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for(auto edge: dislikes){
            int i=edge[0]-1;
            int j=edge[1]-1;
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
        
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && !dfs(graph,i,color,1)) return false;
        }
        return true;
    }
};