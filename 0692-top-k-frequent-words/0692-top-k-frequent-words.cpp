class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto x:words) mp[x]++;
        priority_queue<pair<int,string>>pq;
        vector<string> ans;
        for(auto k:mp){
            pq.push({k.second,k.first});
        }
        while(k>0){
            priority_queue<string,vector<string>,greater<string>>temp;
            int x = pq.top().first;
            while(pq.size() && pq.top().first==x){
                string y = pq.top().second;
                temp.push(y);
                pq.pop();
            }
            while(k>0 && temp.size()){
                ans.push_back(temp.top());
                temp.pop(); 
                k--;
            }            
        }
        return ans;
    }
};