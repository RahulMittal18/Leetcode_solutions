// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:

  
  
    int minJumps(int arr[], int n){
        if(n==1) return 0;
        int i=0;
        int jump  = 1;
        int maxR = arr[0];
        int currR = arr[0];
        while(i<n-1){
            maxR= max(maxR, i+arr[i]);
            if(i==currR && arr[i]==0&& maxR==currR) return -1;
            if(i==currR){
                jump++;
                currR = maxR;
            }
            i++;
        }
        
        return jump;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends