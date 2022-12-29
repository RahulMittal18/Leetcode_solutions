class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& givenTasks) {
        int n = givenTasks.size();
        vector<int> ans;
        vector<vector<int>> tasks;
        for(int i=0;i<n;i++) tasks.push_back({givenTasks[i][0],givenTasks[i][1],i});
        sort(tasks.begin(),tasks.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        long long t=0;
        int i=0;
        while(i<n || !pq.empty()){
            while(i<n && t>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(i<n && pq.empty()) t=tasks[i][0];
            if(!pq.empty()){
                t+=pq.top().first;
                ans.push_back(pq.top().second);
                pq.pop();
            }  
        }
        return ans;
    }
};