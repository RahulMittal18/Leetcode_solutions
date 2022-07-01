// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    static const int mod = 1e9 + 7;
    static const int sz = 2;
    struct Mat{
        
        long long int m[sz][sz];
        Mat(){
            memset(m, 0, sizeof(m));
        }
        void identity(){
            for(int i=0;i<sz;i++) m[i][i]=1;
        }
        
        // Operator overloading
        Mat operator * (Mat a){
            Mat res;
            for(int i=0;i<sz;i++){
                for(int j=0;j<sz;j++){
                    for(int k=0;k<sz;k++){
                        res.m[i][j]+=((m[i][k]%mod *a.m[k][j]%mod)%mod);
                        res.m[i][j]%=mod;
                    }
                }
            }
            return res;
        }
    };
    


    int FindNthTerm(long long int n) {
        Mat res;
        res.identity();
        Mat T;
        // n-=1;
        T.m[0][0]=T.m[0][1]=T.m[1][0]=1;
        if(n<=1) return 1;
        n-=1;
        while(n){
            if(n&1) res=res*T;
            T=T*T;
            n/=2;
        }
        return (res.m[0][0]%mod + res.m[0][1]%mod)%mod;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends