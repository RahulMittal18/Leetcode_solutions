// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int s=0;s<sum+1;s++){
                if(i==0 and s!=0) dp[i][s]=false;
                else if(s==0) dp[i][s]=true;
                else if(arr[i-1]<=s) dp[i][s] = dp[i-1][s] || dp[i-1][s-arr[i-1]];
                else dp[i][s] = dp[i-1][s];
            }
        }
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends