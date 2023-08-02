class Solution {
public:
    void solve(int i,int n,vector<int>&arr,vector<vector<int>>&ans){
        if(i==n){
            ans.push_back(arr);
            return;
        }
        for(int k=i;k<n;k++){
            swap(arr[i],arr[k]);
            solve(i+1,n,arr,ans);
            swap(arr[i],arr[k]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums.size(),nums,ans);
        return ans;
    }
};