class Solution {
public:
    int pre[51][51];
    int dp[51][51][11];
    int mod = 1e9 + 7;
    int row,col;
    int applesCount(int t,int b,int l,int r){
        return pre[b+1][r+1]+pre[t][l]-pre[b+1][l]-pre[t][r+1];
    }
    
    int solve(int t,int b,int l,int r,int k){
        if(t>=row || l>=col) return 0;
        if(k==0){
            if(applesCount(t,b,l,r)>0) return 1;
            else return 0;
        }
        if(dp[t][l][k]!=-1) return dp[t][l][k];
        int ways = 0;
        
        for(int i=t;i<b;i++){
            if(applesCount(t,i,l,r)>0){
                ways = (ways + solve(i+1,b,l,r,k-1)) % mod;
            }
        }
        
        for(int i=l;i<r;i++){
            if(applesCount(t,b,l,i)>0){
                ways = (ways + solve(t,b,i+1,r,k-1)) % mod;
            }
        }
        
        return dp[t][l][k]=ways;
    }
    
    int ways(vector<string>& pizza, int k) {
        memset(pre,0,sizeof(pre));
        memset(dp,-1,sizeof(dp));

        row = pizza.size();
        col = pizza[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pizza[i][j]=='A') pre[i+1][j+1]=1;
                pre[i+1][j+1] += pre[i][j+1] + pre[i+1][j] - pre[i][j];
            }
        }
        
        return solve(0,row-1,0,col-1,k-1);
    }
};