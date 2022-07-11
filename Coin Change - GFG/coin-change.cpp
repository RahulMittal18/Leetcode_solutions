// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    long long f(int S[],int i, int m, int tar, vector<vector<long long int>> &dp){
        
        if(tar==0) return 1;
        if(i==m) return 0;
        if(dp[i][tar]!=-1) return dp[i][tar];
        
        long long int nt = f(S,i+1,m,tar,dp);
        long long int t = 0;
        if(tar>=S[i]){
            t=f(S,i,m,tar-S[i],dp);
        }
        return dp[i][tar]=t+nt;
    }
  
    long long int count(int S[], int m, int n) {

        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,-1));
        return f(S,0,m,n,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends