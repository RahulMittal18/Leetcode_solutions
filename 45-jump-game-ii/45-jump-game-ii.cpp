class Solution {
public:
    int helper(vector<int> &arr, int i,int n,int dp[]){
        if(i==n-1){
            return 0;
        }
        if(i>=n){
            return INT_MAX;
        }
        if(dp[i]==-1){
            int temp = INT_MAX;
            for(int j=i+1;j<=arr[i]+i;j++){
                int sub = helper(arr,j,n,dp);
                if(sub!=INT_MAX) {
                    temp=min(1+sub,temp);
                }
            }
            return dp[i]=temp;
        }
        else{
            return dp[i];
        }
    }
    int jump(vector<int>& arr) {
        int n = arr.size();
        int dp[n];
        memset(dp,-1,sizeof dp);
        int tt = helper(arr,0,n,dp);
        if(tt==INT_MAX) return -1;
        return tt;
    }
};