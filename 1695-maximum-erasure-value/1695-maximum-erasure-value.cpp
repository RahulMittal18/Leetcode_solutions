class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> mp;
        int i=0;
        int r=0;
        int ans=0;
        int temp=0;
        while(i<nums.size()){
            if(mp[nums[i]]==0){
                temp+=nums[i];
                mp[nums[i]]++;
                i++;
                ans=max(ans,temp);
            }
            else{
                while(nums[r]!=nums[i] and r<i){
                    temp-=nums[r];
                    mp[nums[r]]--;
                    r++;          
                }
                i++;
                r++;
            }
        }
        return ans;
    }
};