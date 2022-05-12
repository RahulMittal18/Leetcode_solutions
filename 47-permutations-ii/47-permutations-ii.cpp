class Solution {
public:
    void solve(vector<int> nums,int i,set<vector<int>>& s,vector<int> temp){
        if(i==nums.size()) {
            s.insert(nums);
            return;
        }
        
        for(int j=i;j<nums.size();j++){
            if(j!=i and nums[j]==nums[i]) continue;
            swap(nums[i],nums[j]);
            solve(nums,i+1,s,{});
            swap(nums[i],nums[j]);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        solve(nums,0,s,{});
        for (auto x:s)
            ans.push_back(x);
        return ans;
    }
};