class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int>s;
        for(auto e:arr){
            mp[e]++;
        }
        
        for(auto k:mp){
            if(s.count(k.second)) return false;
            s.insert(k.second);
        }
        return true;
    }
};