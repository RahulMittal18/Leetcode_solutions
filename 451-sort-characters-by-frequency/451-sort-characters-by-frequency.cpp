class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(char x:s){
            mp[x]++;
        }
        
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        for(auto k :mp){
            pq.push({k.second,k.first});
        }
        string ans="";
        while(!pq.empty()){
            auto popped = pq.top();
            pq.pop();
            for(int j=0;j<popped.first;j++){
                ans+=(popped.second);
            }
        }
        return ans;
    }
};