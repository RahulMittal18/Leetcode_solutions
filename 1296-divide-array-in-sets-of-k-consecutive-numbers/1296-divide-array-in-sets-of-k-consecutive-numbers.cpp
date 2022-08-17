class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto &num:nums) mp[num]++;
        int i=0;
        int n = nums.size();
        while(i<n){
            if(mp[nums[i]]>0){
                for(int j=0;j<k;j++){
                    if(mp[nums[i]+j]>0){
                        mp[nums[i]+j]--;
                    }
                    else{
                        return false;
                    }
                }
            }
            i++;
        }
        return true;
    }
};