class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(), [](auto &a, auto &b){return a[1]<b[1];});
        priority_queue<int> pq;
        int curr = 0;
        for(auto course:courses){
            int dur = course[0];
            int end = course[1];
            if(curr+dur<=end) curr+=dur,pq.push(dur);
            else if(!pq.empty() && pq.top()>dur) {
                curr+=(dur-pq.top());
                pq.pop();
                pq.push(dur);  
            }
        }
        return pq.size();
    }
};