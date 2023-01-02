//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        multiset<vector<int>> intervals;
        for(int i=0;i<N;i++){
            intervals.insert({start[i],end[i]});
        }
        int ans = 0;
        int x =0;
        while(intervals.size()>0){
            auto it = intervals.upper_bound({x,1000000000});
            if(it==intervals.end()){
                ans++;
                x=0;
            }
            else{
                // cout<<(*it)[0]<<(*it)[1]<<endl;
                x = (*it)[1]-1;
                intervals.erase(it);
            }
            // cout<<x<<" "<<ans<<endl;
        }
        if(x!=0) ans++;
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends