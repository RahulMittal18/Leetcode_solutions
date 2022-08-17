class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int i=0;
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