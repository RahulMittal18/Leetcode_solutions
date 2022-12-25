class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        map<int,int> mp;
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(auto &e:nums) mp[e]++;
        for(auto q: queries){
            int t=q;
            int temp=0;
            for(int i=0;i<nums.size();i++){
                if(t-nums[i]<0) break;
                t-=nums[i];
                temp++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};