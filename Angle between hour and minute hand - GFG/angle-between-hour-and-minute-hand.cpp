// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getAngle(int H , int M) {
        float h = 30*H +0.5*M;
        float m = 6*M;
        int ans,ans2 ;
        if(h>m){
            ans=(h-m);
            ans2 = 360-h+m;
        }
        else{
            ans = m-h;
            ans2=360-m+h;
        }
        return min(ans,ans2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int H,M;
        
        cin>>H>>M;

        Solution ob;
        cout << ob.getAngle(H,M) << endl;
    }
    return 0;
}  // } Driver Code Ends