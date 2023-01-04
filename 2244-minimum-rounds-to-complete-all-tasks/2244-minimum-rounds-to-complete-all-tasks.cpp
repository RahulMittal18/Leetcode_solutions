class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int x:tasks) mp[x]++;
        int ans = 0;
        for(auto [k,v]:mp){
            if(v<2) return -1;
            ans+=v/3;
            if(v%3!=0) ans++;
        }
        return ans;
    }
};