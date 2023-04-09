class Solution {
public:
    
    int solve(vector<vector<int>>&nums,int m,int n,int i,int j,vector<vector<bool>>&vis,vector<vector<int>> &dp){
        if(i==m-1 && j==n-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        vis[i][j]=true;
        int newx = i + nums[i][j];
        int newy = j + nums[i][j];
        int x =1e5;
        for(int ii =i+1;ii<=min(m-1,newx);ii++){
            if(!vis[ii][j]){
                x=min(x,1+solve(nums,m,n,ii,j,vis,dp));
            }    
        }
        for(int ii =j+1;ii<=min(n-1,newy);ii++){
            if(!vis[i][ii]){
                x=min(x,1+solve(nums,m,n,i,ii,vis,dp));
            }    
        }
        return dp[i][j]=x;
    }
    
    int minimumVisitedCells(vector<vector<int>>& nums) {
        queue<pair<int,int>> q;
        q.push({0,0});
        int m = nums.size();
        int n = nums[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<int> max_i(n),max_j(m);
        int ans = 0;

        while(!q.empty()){
            ans++;
            int nn = q.size();
            for(int jj=0;jj<nn;jj++){
                auto x = q.front();
                q.pop();
                int i = x.first;
                int j = x.second;
                vis[i][j]=true;
                if(i==m-1 && j==n-1) return ans;
                int newx = i + nums[i][j];
                int newy = j + nums[i][j];
                
                for(int k = max(max_i[j],i)+1; k<m && k-i<=nums[i][j];k++){
                    if(!vis[k][j]){
                        q.push({k,j});
                    }    
                }
                for(int k = max(max_j[i],j)+1; k<n && k-j<=nums[i][j];k++){
                    if(!vis[i][k]){
                        q.push({i,k});
                    }   
                }
                max_i[j] = max(max_i[j],newx);
                max_j[i] = max(max_j[i],newy);
            }
        }
        return -1;
        // int x = solve(nums,m,n,0,0,vis,dp);
        // return x>=1e5?-1:x-1;
    }
};