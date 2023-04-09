//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef long long ll;
class Solution {
  public:
    int p = 1e9+7;
    int mod=p;
    ll fact[100001]={0};
    
    void fac(int n){
         fact[0]=1;
            fact[1]=1;
        for(int i=2;i<=n;i++){
            fact[i] = (fact[i-1]*i*1ll)%mod;
        }
        // for(int i=0;i<17;i++){
        //     cout<<fact[i]<<" ";
        // }
        // cout<<endl;
    }
    
    ll powmod(ll a, ll b){
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}
    
    ll inv(ll a){
    return powmod(a, p-2);
}
    
    ll nCk(ll n, ll k){
        return ((fact[n] * inv(fact[k]) % p) * inv(fact[n-k])) % p;
    }
    

  
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
       
        fac(N);
        int cnt = 0;
        int sum = N*A;
        if(A==B){
            bool isOk = false;
            int x = sum;
            while(x>0){
                int y = x%10;
                if((y==C || y==D)) {isOk = true;break;}
                x/=10;
            }
            if(isOk) return 1;
        }
        for(int i=0;i<=N;i++){
            bool isOk = false;
            int x = sum;
            while(x>0){
                int y = x%10;
                if((y==C || y==D)) {isOk = true;break;}
                x/=10;
            }
            // cout<<sum<<" "<<i<<" "<<isOk<<endl;
            if(isOk){
                if(i==0 || i==N){
                    cnt=(cnt+1)%mod;
                }
                else{
                    cnt= (cnt+nCk(N,i))%mod;
                }
                // cout<<nCk(N,i)<<endl;
                
            }
            sum-=A;
            sum+=B;
        }
        return cnt%mod;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends