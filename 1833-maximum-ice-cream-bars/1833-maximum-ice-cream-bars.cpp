class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = costs.size();
        for(int i=0;i<n;i++){
            pq.push(costs[i]);
        }
        int ans = 0;
        while(pq.size()){
            if(pq.top()>coins) break;
            ans++;
            coins-=pq.top();
            pq.pop();
        }
        return ans;
    }
};