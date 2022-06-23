// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    long long int mod = 1e9+7;
	    long long int dp[N+1];
	    dp[1]=2;
	    dp[2]=3;
	    for(int i=3;i<=N;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
	    return ((dp[N]%mod)*(dp[N]%mod))%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends