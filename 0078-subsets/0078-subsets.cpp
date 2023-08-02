class Solution {
public:
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;          //Final ans
        vector<int> curr_vec;             //Stores the current subset while computing
        solve(nums, 0, curr_vec, ans);   //start at index 0
        return ans;
    }
    
    void solve(vector<int> nums, int curr, vector<int> &curr_vec, vector<vector<int>> &ans){
        if(curr == n){                          //Each time when u go out of the array, push the curr array into the result 
            ans.push_back(curr_vec);
            return;
        }
        solve(nums, curr+1, curr_vec, ans);     //do not include the current element
		
        curr_vec.push_back(nums[curr]);        //include the current element
        solve(nums, curr+1, curr_vec, ans);   //traverse to the next element
		
        curr_vec.pop_back();                 //Backtracing
    }
};