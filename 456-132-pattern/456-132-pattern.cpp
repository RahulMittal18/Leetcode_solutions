class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<vector<int>> st;
        int minm_on_left = nums[0];
        for(int i=1;i<nums.size();i++){
            while(!st.empty() and st.top()[0]<=nums[i]){
                st.pop();
            }
            if(!st.empty() and nums[i]>st.top()[1])
                return true;
            st.push({nums[i],minm_on_left});
            minm_on_left = min(minm_on_left,nums[i]);

        }
        return false;
    }
};