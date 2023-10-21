class Solution {
public:
    int constrainedSubsetSum(vector<int>& arr, int k) {
        int ans = arr[0];
        int sum = 0;
        int n = arr.size();
        priority_queue<pair<int,int>> pq;
        pq.push({arr[0],0});
        for(int i=1;i<n;i++){
            while(!pq.empty() && i-pq.top().second>k){
                pq.pop();
            }
            int y = pq.top().first;
            pq.push({max(arr[i],y+arr[i]),i});
            
            ans = max({ans,arr[i],y+arr[i]});            
        }
        return ans;
    }
};