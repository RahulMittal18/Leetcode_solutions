class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<pair<long long,long long>> v;
        int mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        long long ans = 0;
        sort(v.rbegin(),v.rend());
        long long temp=0;
        for(int i=0;i<n;i++){
            if(pq.size()<k){
                temp+=v[i].second;
                pq.push(v[i].second);
            }
            else{
                long long x = pq.top();
                pq.pop();
                pq.push(v[i].second);
                temp = (temp-x+v[i].second);
            }
            long long a = (v[i].first*temp);
            if(a>ans) ans = a;
        }
        return ans%mod;
    }
};