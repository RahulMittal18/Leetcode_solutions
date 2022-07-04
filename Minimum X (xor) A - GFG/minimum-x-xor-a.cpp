// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int set_bits = 0;
        for(int i=0;i<32;i++){
            if(b&(1<<i)) set_bits++;
        }
        // cout<<set_bits;
        int ans = 0;
        for(int i=31;i>=0;i--){
            if(set_bits<=0) break;
            if(a&(1<<i)) {
                // cout<<i<<endl;
                set_bits--;
                ans ^=(1<<i);
            }
        }
        // cout<<ans;
        int i=0;
        while(set_bits>0 and i<32){
            if(ans&(1<<i)){}
            else{
                ans ^= (1<<i);
                set_bits--;
            }
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends