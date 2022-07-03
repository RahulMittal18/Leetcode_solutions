// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> ans;
    unordered_set<string> dic;
    void solve(string &s,int i,string temp){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        
            for(int j=i;j<s.size();j++){
                string x = s.substr(i,j-i+1);
                string sp = " ";
                if(dic.find(x)!= dic.end()){
                    solve(s,j+1,temp + x +sp);
                }
            }
    }


    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        for(string x:dict) dic.insert(x);
        string temp ="";
        solve(s,0,temp);
        for(string &s:ans){
            s.pop_back();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends