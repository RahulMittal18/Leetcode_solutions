class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=-1;
        if(nums.size()<2) return false;
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            sum+=x;
            if(mp.find(sum%k)!=mp.end()){
                if(mp[sum%k]<i-1) return true;
            } 
            else mp[sum%k]=i;
        }
        return false;
    }
};