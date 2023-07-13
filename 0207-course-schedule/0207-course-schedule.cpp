class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> in(n, 0);
        vector<vector<int>> adj(n);
        for(auto x:prerequisites){
            in[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        int count = n;
        while(!q.empty()){
            int node = q.front(); q.pop();
            count -= 1;
            for(auto nei: adj[node]){
                if(in[nei]==1){
                    q.push(nei);
                }
                in[nei]--;
            }
        }
        return count == 0;
    }
};