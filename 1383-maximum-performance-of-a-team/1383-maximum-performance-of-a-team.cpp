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
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        long long temp=0;
        long long prev,curr;
        for(int i=0;i<n;i++){
            if(pq.size()<k){
                temp+=v[i].second;
                pq.push(v[i].second);
            }
            else{
                long long x = pq.top();
                prev = (temp*v[i-1].first);
                curr = ((temp-x+v[i].second)*v[i].first);
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