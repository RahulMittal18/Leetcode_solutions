class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        priority_queue<pair<int,int>> pq;
        vector<int> seen(n,-1);
        pq.push({maxMoves,0});
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            
            if(seen[t.second]==-1){
                int moves = t.first;
                int node = t.second;
                seen[node] = moves;
                for(auto neighbor : adj[node]){
                    int nei = neighbor.first;
                    int steps = neighbor.second;
                    if(seen[nei]==-1 && 0 <= moves - steps - 1){
                        pq.push({moves-steps-1,nei});
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) ans = seen[i]>=0 ? ans+1:ans;
        for(auto e:edges){
            int x = seen[e[0]]>=0 ? seen[e[0]]:0;
            int y = seen[e[1]]>=0 ? seen[e[1]]:0;

            ans+=min(x+y,e[2]);
        }
        return ans;
    }
};