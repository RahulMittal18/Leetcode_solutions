class Solution {
public:
    vector<int> adj[100005];
    int dp[100005][15];
    int k;

    int dfs2(int src,int par,int times,vector<int> &coins){
        int choice1 = 0, choice2 = 0;
        if(dp[src][times]!=-1) return dp[src][times];
        
        for(auto nei:adj[src]){
            if(par==nei) continue;
            choice1 += dfs2(nei,src,min(14,times+1),coins);
            choice2 += dfs2(nei,src,times,coins);
        }
        
        int coinsAvailableAtSource = coins[src]/(1<<times);
        choice1 += coinsAvailableAtSource/2;
        choice2 += coinsAvailableAtSource-k;

        return dp[src][times] = max(choice1, choice2);
    }
    
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int kk) {
        k = kk;
        memset(dp,-1,sizeof(dp));
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs2(0,-1,0,coins);   
    }
};