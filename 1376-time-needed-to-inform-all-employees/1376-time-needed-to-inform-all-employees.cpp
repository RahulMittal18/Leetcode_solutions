class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1) graph[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push({headID,0});
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            
            for(int i=0;i<s;i++){
                auto p = q.front();
                q.pop();
                for(auto nei:graph[p.first]){
                    ans = max(ans,p.second+informTime[p.first]);
                    q.push({nei,p.second+informTime[p.first]});
                }
            }   
        }
        return ans;
    }
};