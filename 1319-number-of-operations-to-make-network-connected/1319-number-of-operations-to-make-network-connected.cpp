class Solution {
public:
    
    int find(vector<int> &parent, int v){
        int root = v;
        while(root != parent[root]){
            root = parent[root];
        }
        
        return root;
    }
    
    void unify(vector<int> &parent, int u, int v){
        int root_u = find(parent, u);
        int root_v = find(parent, v);
        
        if(root_u == root_v){
            return;
        }
        parent[root_u] = root_v;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int i, j, used = 0, redundent = 0, total = 0;
        vector<int> parent(n);
        for(i = 0; i < n; i++){
            parent[i] = i;
        }
        
        for(i = 0; i < connections.size(); i++){
            if(find(parent, connections[i][0]) == find(parent, connections[i][1])){
                redundent++;
            }else{
                used++;
                unify(parent, connections[i][0], connections[i][1]);
            }
        }
        
        for(i = 0; i < n; i++){
            total += parent[i] == i? 1 : 0;
        }
        
        // cout << used << " " << redundent << " " << total << endl;
        return total - 1 <= redundent ? total-1 : -1;
    }
};