class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> ind(n);
        iota(ind.begin(),ind.end(),0);
        
        sort(ind.begin(),ind.end(),[&](const int a, const int b) {
            return capital[a] < capital[b];
        });
        
        int j=0;
        priority_queue<int> pq;
        while(k--){
            while(j<n && capital[ind[j]]<=w){
                pq.push(profits[ind[j]]);
                j++;
            }
            if(!pq.size()) break;
            w += pq.top();
            pq.pop();
        }
        return w; 
    }
};