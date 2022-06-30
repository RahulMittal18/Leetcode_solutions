// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int n)
{
        
    int cand = a[0];
    int votes = 1;
    for(int i=1;i<n;i++){
        if(a[i]==cand) votes++;
        else votes--;
        if(votes==0) cand = a[i], votes = 1;
    }
    int count = 0;
    for(int i=0;i<n;i++) if(a[i]==cand) count++;
    return count>n/2 ? cand : -1;
        
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends