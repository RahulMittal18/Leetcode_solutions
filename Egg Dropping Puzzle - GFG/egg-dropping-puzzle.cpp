// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int dp[201][201];
    int solve(int n,int k){
        if(dp[n][k]!=-1) return dp[n][k];
        if(n==1) return k;
        if(k==0 ||k==1) return k;
        int mn = INT_MAX;
        for(int x=1;x<=k;x++){
            int res = max(solve(n-1,x-1),solve(n,k-x));
            mn =  min(mn,res);
        }
        dp[n][k]=mn+1;
        return mn+1;
    }
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        memset(dp,-1,sizeof dp);
        return solve(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends