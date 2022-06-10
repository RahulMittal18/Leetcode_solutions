// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
        int dp[1001][1001];   
    int dfs(int i , int j, vector<vector<int>> & matrix, int curr_val) {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || curr_val >= matrix[i][j]) {
            return 0; 
        }
        if(dp[i][j] != -1) {
            return dp[i][j]; 
        }
        int temp = matrix[i][j]; 
        int one = 1 + dfs(i+1, j, matrix, temp); 
        int two = 1 + dfs(i, j+1, matrix, temp);  
        int three = 1 + dfs(i-1, j, matrix, temp); 
        int four = 1 + dfs(i,j-1, matrix, temp);  
        return dp[i][j] = max({one, two, three, four}); 
    }
  
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {  
        int length = 0; 
        memset(dp, -1, sizeof(dp));  
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int curr = INT_MIN; 
                int temp = dfs(i,j,matrix,curr); 
                length = max(length, temp);  
            }
        }
        return length;  
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends