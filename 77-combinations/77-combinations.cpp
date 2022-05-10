class Solution {
public:
    void solve(int n,int k,vector<int> temp,vector<vector<int>>& ans,int i){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        for(int j=i+1;j<=n;j++){
            temp.push_back(j);
            solve(n,k-1,temp,ans,j);
            temp.pop_back();
        }
    }
       
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        solve(n,k,{},ans,0);
        return ans;
    }
};