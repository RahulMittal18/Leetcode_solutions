class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid,int i,int j,vector<bool>&vis){
        return i<grid.size() && i>=0 && j>=0 && j<grid[0].size() && !vis[i*grid[0].size()+j] && grid[i][j]!=-1;
    }
    
    int helper(vector<vector<int>>& grid,pair<int,int> curr,pair<int,int> end,int steps,vector<bool> &vis,int n){
        if(curr==end){
            return steps==0?1:0;
        }
        // auto [i,j]=curr;
        int i = curr.first;
        int j = curr.second;
        // cout<<"reached "<<i<<" "<<j<<endl;
        vis[i*n+j]=true;
        // for(int i=0;i<n*grid[0].size();i++) cout<<vis[i]<<" ";
        // cout<<endl;
        int dir[5]={0,-1,0,1,0};
        int temp = 0;
        for(int k=0;k<4;k++){
            if(isValid(grid,i+dir[k],j+dir[k+1],vis)){
                temp+=helper(grid,{i+dir[k],j+dir[k+1]},end,steps-1,vis,n);
            }
        }
        vis[i*n+j]=false;
        return temp;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int steps = 1;
        pair<int,int> start,end;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) steps++;
                else if(grid[i][j]==1) start={i,j};
                else if(grid[i][j]==2) end={i,j};
            }
        }
        vector<bool> vis(n*m,false);
        return helper(grid,start,end,steps,vis,n);
    }
};