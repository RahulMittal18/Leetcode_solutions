// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void swap(int* a,int* b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void sort012(int a[], int n)
{
    int l = 0;int m =0;int r = n-1;
    while(m<=r){
        if(a[m]==0){
            swap(&a[m],&a[l]);
            m++;
            l++;
        }
        else if(a[m]==2){
            swap(&a[r],&a[m]);
            r--;
        }
        else{
            m++;
        }
    }
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends