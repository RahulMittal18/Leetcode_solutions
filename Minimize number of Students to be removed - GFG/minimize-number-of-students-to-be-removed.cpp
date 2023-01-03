//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int a[], int N) {
        int n = N;
        const int INF = 1e5;
        vector<int> d(n+1, INF);
        d[0] = -INF;
    
        for (int i = 0; i < n; i++) {
            int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
            if (d[j-1] < a[i] && a[i] < d[j])
                d[j] = a[i];
        }
    
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (d[i] < INF)
                ans = i;
        }
        return N-ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends