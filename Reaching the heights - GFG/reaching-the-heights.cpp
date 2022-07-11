// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++




vector<int> reaching_height(int n, int a[]) {
    vector<int> ans(n);
    sort(a,a+n,greater<int>());
    int j=0;
    if(n>=2 and a[0]==a[n-1]) return {-1};
    for(int i=0;i<n;i++){
        if(i%2==0) {ans[i]=a[j];
        j+=1;}
    }
    
    for(int i=n-1;i>=0;i--){
        if(i%2) {ans[i]=a[j];
        j+=1;}
    }
    return ans;
}
