class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int x:tasks) mp[x]++;
        int ans = 0;
        for(auto k:mp){
            if(k.second<2) return -1;
            ans+=k.second/3;
            if(k.second%3!=0) ans++;
        }
        return ans;
    }
};