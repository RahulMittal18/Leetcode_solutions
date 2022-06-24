// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int level,int i,int pos, int val){
        if (i==1) return 1;
        if(i&1) return solve(level,(i+1)/2,pos,val);
        return !solve(level,(i+1)/2,pos,val);
    }

    char profession(int level, int pos){
        //1 for E , 0 for D
        if(solve(level,pos,pos,1)) return 'e';
        return 'd';
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends