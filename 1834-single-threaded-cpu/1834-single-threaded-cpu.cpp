class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasksArr) {
        map<vector<int>,int> mp;
        int n = tasksArr.size();
        vector<int> ans;
        vector<vector<int>> tasks;
        for(int i=0;i<n;i++) tasks.push_back({tasksArr[i][0],tasksArr[i][1],i});
        sort(tasks.begin(),tasks.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        long long t=0;
        int i=0;
        while(i<n || !pq.empty()){
            while(i<n && t>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                // cout<<t<<"came"<<i<< " "<<pq.top().first<<" "<<pq.top().second<<endl;
                i++;
            }
            if(i<n && pq.empty()) t=tasks[i][0];
            if(!pq.empty()){
                t+=pq.top().first;
                // cout<<t<<"done"<<" "<<pq.top().second<<endl;
                ans.push_back(pq.top().second);
                pq.pop();
            }  
        }
        return ans;
    }
};