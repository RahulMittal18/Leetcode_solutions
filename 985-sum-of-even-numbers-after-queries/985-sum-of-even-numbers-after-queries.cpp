class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long int evenSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) evenSum+=nums[i];
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int ind = queries[i][1];
            int val = queries[i][0];
            if(nums[ind]%2==0)
            evenSum-=nums[ind];
            nums[ind]+=val;
            if(nums[ind]%2==0){
                evenSum+=nums[ind];
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};