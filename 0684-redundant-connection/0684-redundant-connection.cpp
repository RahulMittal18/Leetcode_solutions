class Solution {
public:
    vector<int> par;
    int findParent(int node){
        if(node==par[node]) return node;
        return par[node] = findParent(par[node]);
    }
    
    int unite(int node1,int node2){
        int p1 = findParent(node1);
        int p2 = findParent(node2);
        if(p1==p2) return -1;
        return par[p1]=p2;   
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
        vector<int> ans;
        for(auto e:edges){
            if(unite(e[0]-1,e[1]-1)==-1) ans = e;
        }
        return ans;
    }
};