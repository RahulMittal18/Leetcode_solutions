class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>> q;
        maze[entrance[0]][entrance[1]]='+';
        q.push({entrance[0],entrance[1]});
        int ans = 0;
        int dir[5]={0,1,0,-1,0};
        while(!q.empty()){
            int nn = q.size();
            while(nn--){
                int i,j;
                tie(i,j) = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x = i+dir[k];
                    int y = j+dir[k+1];
                    if(x<0 || y<0 || x>=m || y>=n || maze[x][y]=='+') continue;                    
                    if(x==0 or x==m-1 or y==0 or y==n-1) return ans+1;
                    maze[x][y]='+';
                    q.push({x,y});
                    
                }
            }
            ans++;
        }
        return -1;
    }
};