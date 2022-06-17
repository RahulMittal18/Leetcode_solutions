class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,int src,int target,vector<int> &temp,vector<vector<int>> &ans){
        if(src==target){
            ans.push_back(temp);
            return;
        }
        for(auto x:graph[src]){
            temp.push_back(x);
            dfs(graph,x,target,temp,ans);
            temp.pop_back();
        }
    }
    
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(graph,0,graph.size()-1,temp,ans);
        return ans;
    }
};