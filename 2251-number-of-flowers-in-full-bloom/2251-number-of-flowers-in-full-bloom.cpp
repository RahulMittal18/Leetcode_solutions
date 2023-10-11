class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // vector<pair<int,int>> arr;
        map<int,int> mp,mp2;
        for(auto f:flowers){
            mp[f[0]]++;
            mp[f[1]+1]--;
        }
        int curr = 0;
        mp[0]=0;
        for(auto [k,v]:mp){
            curr+=v;
            mp2[k] = curr;
            // arr.push_back({k,curr});
        }
        vector<int> ans;
        for(auto q:people){
            auto it = mp2.lower_bound(q);
            if(it->first!=q) it--;
            ans.push_back(it->second);
        }
        return ans;
    }
};