// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:


    void f(int i,int j,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &ans,vector<int> &temp){
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(i==n-1 and j==m-1) {
            // cout<<"h";
            temp.push_back(grid[i][j]);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        temp.push_back(grid[i][j]);
        // cout<<"g";
        f(i+1,j,n,m,grid,ans,temp);
        // cout<<"h";
        
        // temp.pop_back();
        //  temp.push_back(grid[i][j]);
        f(i,j+1,n,m,grid,ans,temp);
        // cout<<"i";
        temp.pop_back();
        // cout<<"j";
        
    }


    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,0,n,m,grid,ans,temp);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends