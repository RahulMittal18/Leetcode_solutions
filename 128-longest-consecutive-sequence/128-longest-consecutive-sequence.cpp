class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans = 0;
        sort(nums.begin(),nums.end());
        int l=0;
        int i;
        int count =1;
        for(i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]!=nums[i-1]+1){
                ans = max(ans,count);
                count=1;
            }
            else{
                count++;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};