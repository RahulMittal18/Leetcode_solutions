class Solution {
public:
    void solve(int i,int n,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int k=i;k<n;k++){
            swap(arr[i],arr[k]);
            temp.push_back(arr[i]);
            solve(i+1,n,arr,temp,ans);
            temp.pop_back();
            swap(arr[i],arr[k]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums.size(),nums,temp,ans);
        return ans;
    }
};