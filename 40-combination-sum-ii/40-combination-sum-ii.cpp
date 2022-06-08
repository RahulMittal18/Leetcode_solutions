class Solution {
public:
    void solve(int i,vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int j=i;j<candidates.size();j++){
            if (j > i && candidates[j] == candidates[j-1]) continue;
                temp.push_back(candidates[j]);
                solve(j+1,candidates,target-candidates[j],ans,temp);
                temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,ans,temp);

        return ans;
    }
};