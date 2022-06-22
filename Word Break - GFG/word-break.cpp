// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> dict(B.begin(),B.end());
        int n = A.size();
        int dp[n+1];
        memset(dp,-1,sizeof dp);
        dp[0]=1;
        
        for(int i=1;i<=n;i++){
            string word="";
            for(int j=i-1;j>=0;j--){
                word=A[j]+word;
                if(dict.count(word)!=0){
                    if(dp[j]==1) dp[i]=1;
                }
            }
        }
        return dp[n]==1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends