class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int n = nums.size();
        int i=0;
        while(i<k) pq.push(nums[i++]);
        while(i<n){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
        return pq.top();
    }
};