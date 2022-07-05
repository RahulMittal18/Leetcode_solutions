class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans = 0;
        unordered_set<int> s(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i]-1)==0){
                int curr = 1;
                int num=nums[i];
                while(s.count(num+1)==1) num++,curr++;
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};