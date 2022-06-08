// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    void dfs(bool *visited, vector<int>&stack, int i, vector<int>adj[]) {
        visited[i] = true;
        for(auto nbr: adj[i]) {
            if(!visited[nbr]) {
            dfs(visited, stack, nbr, adj);
            }
        }
        stack.push_back(i);
    }
    void dfs2(bool *visited, int i, vector<int>adj[]) {
        visited[i] = true;
        for(auto nbr: adj[i]) {
            if(!visited[nbr]) {
            dfs2(visited, nbr, adj);
            }
        }
        // stack.push_back(i);
    }
    int solve(int V, vector<int> adj[], vector<int>reverseadj[]) {
        bool visited[V] = {0};
        vector<int>stack;
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(visited, stack, i, adj);
            }
        }
        // visited[V] = {0};
        int ans = 0;
        for(auto &x:visited) x=0;
        for(int i = stack.size()-1; i >= 0; i--) {
            if(!visited[stack[i]]) {
                dfs2(visited, stack[i], reverseadj);
                ans++;
            }
        }
        return ans;
    }
    public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int>reverseadj[V];
        for(int i = 0; i < V; i++) {
            for(auto nbr: adj[i]) {
                reverseadj[nbr].push_back(i);
            }
        }
        return solve(V, adj, reverseadj);
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends