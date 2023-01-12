class Solution {
public:
    
    vector<int> solve(vector<vector<int>> &adj,int src,string &labels,int par,vector<int> &freq,vector<int> &ans,int n){
        vector<int> temp(26,0);
        for(auto nei:adj[src]){
            vector<int> child(26,0);
            if(nei!=par){
                child = solve(adj,nei,labels,src,freq,ans,n);
            }
            for(int i=0;i<26;i++){
                temp[i]+=child[i];
            }
        }
        temp[labels[src]-'a']++;
        ans[src]=temp[labels[src]-'a'];
        return temp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> freq(26,0);
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n,0);
        // for(auto e:freq) cout<<e<<endl;
        solve(adj,0,labels,-1,freq,ans,n);
        return ans;
    }
};