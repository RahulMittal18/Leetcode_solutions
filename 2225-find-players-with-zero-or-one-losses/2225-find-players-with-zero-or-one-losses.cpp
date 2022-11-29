class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto e:matches){
            mp[e[0]]=0;
        }
        for(auto e:matches){
            mp[e[1]]++;
        }
        vector<vector<int>> ans={{},{}};
        for(auto k:mp){
            if(k.second==0){
                ans[0].push_back(k.first);
            }
            else if(k.second==1){
                ans[1].push_back(k.first);
            }
        }
        return ans;
    }
};