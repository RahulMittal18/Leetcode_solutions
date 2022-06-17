class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int src,vector<bool>& vis){
            vis[src]=true;
            for(auto x: rooms[src]){
                if(!vis[x]) dfs(rooms,x,vis);
            }
        }
        
    bool canVisitAllRooms(vector<vector<int>>& rooms) {        
        vector<bool> vis(rooms.size());
        dfs(rooms,0,vis);
        for(auto x:vis){
            if(!x) return false;
        }
        return true;
    }
};