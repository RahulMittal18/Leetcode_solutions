class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(auto x:spells){
            long long req = ((success-1)/x)+1;
            auto it = lower_bound(potions.begin(),potions.end(),req);
            if(it==potions.end()) ans.push_back(0);
            else ans.push_back(potions.end()-it);
        }
        return ans;
    }
};