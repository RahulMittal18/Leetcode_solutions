class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        priority_queue<int> pq;
        for(auto k:mp){
            pq.push(k.second);
        }
        int ans=0;
        int running_sum=0;
        while(running_sum<n/2){
            running_sum+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};