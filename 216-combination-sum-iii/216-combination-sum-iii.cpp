class Solution {
public:
    void solve(int n, int k,vector<int> temp, vector<vector<int>>& ans,int i){
        if(k==0){
            if(n!=0) return;
            else ans.push_back(temp);
        }
        if(n<=0) return;
        
        for(int j=i+1;j<10;j++){
            temp.push_back(j);
            solve(n-j,k-1,temp,ans,j);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        solve(n,k,{},ans,0);
        return ans;
    }
};