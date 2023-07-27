//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,int n,vector<vector<int>>&maze,string &temp,vector<string>&ans){
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        maze[i][j]=0;
        vector<int> dirs = {0,1,0,-1,0};
        string chr = "RDLU";
        for(int k=0;k<4;k++){
            int x = i+dirs[k];
            int y = j+dirs[k+1];
            if(x>=0 && y>=0 && x<n && y<n && maze[x][y]){
                temp.push_back(chr[k]);
                solve(x,y,n,maze,temp,ans);
                temp.pop_back();
            }
        }
        maze[i][j]=1;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string temp="";
        vector<string> ans;
        if(m[0][0]!=0) solve(0,0,n,m,temp,ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends