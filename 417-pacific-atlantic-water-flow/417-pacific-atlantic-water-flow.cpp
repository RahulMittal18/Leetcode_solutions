class Solution {
public:  
    int m,n;
    void dfs(vector<vector<int>> &heights,vector<vector<bool>> &visited,int i,int j){

        visited[i][j]=true;
        
        int dir[5]={0,1,0,-1,0};
        for(int k=0;k<4;k++){
            int x = i+dir[k];
            int y = j+dir[k+1];
            if(x>=0 and y>=0 and x<m and y<n and !visited[x][y] and heights[i][j]<=heights[x][y])
                dfs(heights,visited,x,y);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool> (n,false));
        vector<vector<bool>> atlantic(m,vector<bool> (n,false));
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)
                    dfs(heights,pacific,i,j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1 || j==n-1)
                    dfs(heights,atlantic,i,j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]&&atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};