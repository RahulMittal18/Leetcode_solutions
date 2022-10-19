class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int kk) {
        map<string,int> mp;
        for(auto x:words) mp[x]++;
        vector<string> ans;
        
        map<int,vector<string>> t;
        for(auto k:mp){
            t[k.second].push_back(k.first);
        }
        // for(auto k:t) cout<<k.first<<" "<<k.second.size()<<endl;
        for(auto k = t.rbegin();k!=t.rend() && kk>0;k++){
            vector<string> c = k->second;
            // for(auto x:c) cout<<x<<endl;
            sort(c.begin(),c.end());
            int n = c.size();
            int z = min(kk,n);
            for(int i =0;i<z;i++){
                // cout<<c[i]<<endl;
                ans.push_back(c[i]);
                kk--;
            }
        }
        return ans;
    }
};