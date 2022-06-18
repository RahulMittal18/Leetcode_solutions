enum Color {WHITE, GRAY, BLACK};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        int i = 0;

        // Reverse Edges of graph
        for(auto& g : graph) {
            for(auto& it : g) {
                adj[it].push_back(i);
                indegree[i]++;
            }
            i++;
        }

        // Topo Sort
        queue<int> q;

        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> safeNodes;

        while(q.size()) {
            int node = q.front(); q.pop();

            safeNodes.push_back(node);

            for(auto& adjnode : adj[node]) {
                if(--indegree[adjnode] == 0) q.push(adjnode);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};