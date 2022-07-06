class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int arr[n+1];
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<n+1;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};