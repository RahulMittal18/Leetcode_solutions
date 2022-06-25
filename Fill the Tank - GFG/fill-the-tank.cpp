// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    bool overdemand = false;
    long long int maxcap = 1e18;
    long long int dfs(vector<vector<int>> &graph,int src,int *Cap, vector<int> &vis){
        vis[src]=1;
        long long int count_nei = 0;
        long long int temp = 0;
        for(auto nei : graph[src]){
            if(vis[nei]==-1){
                long long int t = dfs(graph,nei,Cap,vis);
                temp = max(temp,t);
                count_nei++;
            }
        }
        long long int a = temp*count_nei + Cap[src];
        if(a>maxcap) overdemand = true;
        return a;
    }



    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
       vector<int> vis(N,-1);
    //   memset(vis,-1,sizeof vis);
       vector<vector<int>> graph(N);
       for(auto x:Edges){
           graph[x[0]-1].push_back(x[1]-1);
           graph[x[1]-1].push_back(x[0]-1);
       }
       long long int xyz = dfs(graph,S-1,Cap,vis);
       return overdemand? -1 : xyz ;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends