// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int dp[81];
    long long int solve(long long int n){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        long long int a1=0,a2=0;
        if(n>=4){
            a2 = solve(n-4);
        }
        a1 = solve(n-1);
        return dp[n]=a1+a2;
    }


    long long int arrangeTiles(long long int N){
        // if(N==1) return 1;
        memset(dp,-1,sizeof dp);
        return solve(N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends