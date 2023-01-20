class Solution {
public:
    void solve(int i,int n,vector<int>& nums,set<vector<int>>&ans,vector<int>&temp) {
        if(i==n){
            if(temp.size()>=2)
            ans.insert(temp);
            return;
        }
        if(!temp.size() || nums[i]>=temp.back()){
            temp.push_back(nums[i]);
            solve(i+1,n,nums,ans,temp);
            temp.pop_back();
        }
        solve(i+1,n,nums,ans,temp);
    }

    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        solve(0,n,nums,ans,temp);
        return vector(ans.begin(),ans.end());
    }
};