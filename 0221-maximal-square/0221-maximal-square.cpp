class Solution {
public:
    
    bool check(vector<vector<int>>&dp,int side,int one){
        if(side==0) return true;
        int n = dp.size();
        int m = dp[0].size();
        for(int i=side;i<n;i++){
            for(int j=side;j<m;j++){
                int x = dp[i][j];
                if(i-side>=0){
                    x-=dp[i-side][j];
                }
                if(j-side>=0){
                    x-=dp[i][j-side];
                }
                x+=dp[i-side][j-side];
                if(x==side*side) return true;
            }
        }
        return false;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int one=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i+1][j+1]=matrix[i][j]=='1'?1:0;
                one+=dp[i+1][j+1];
                dp[i+1][j+1]+=dp[i+1][j]+dp[i][j+1];
                dp[i+1][j+1]-=dp[i][j];
        }
        }

        
        
        int low = 0;
        int ans = 0;
        int high = min(m,n);
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(dp,mid,one)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans*ans;
    }
};