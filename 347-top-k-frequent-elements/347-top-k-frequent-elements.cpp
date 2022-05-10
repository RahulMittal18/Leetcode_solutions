class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(auto key:mp){
            pq.push({key.second,key.first});
        }
        vector<int> ans;
        while(k--){
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};