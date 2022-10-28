class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        for(auto x:strs){
            string b = x;
            sort(x.begin(),x.end());
            mp[x].push_back(b);
        }
        for(auto k:mp){
            vector<string> temp;
            for(auto e:k.second){
                temp.push_back(e);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};