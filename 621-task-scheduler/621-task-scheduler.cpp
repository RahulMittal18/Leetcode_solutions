class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq,temp;
        int freq[26]={0};
        for(auto x:tasks) freq[x-'A']++;
        int time = 1;
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0) pq.push({freq[i],'A'+ i });
        }
        
        unordered_map<char,int> mp;
        for(int i=0;i<26;i++){
            mp['A'+i] = -n;
        }
        
        while(!pq.empty()){
            for(int i=0;i<=n;i++){
                if(pq.empty()){ time++; continue;}
                auto top = pq.top();
                pq.pop();
                
                if(mp[top.second]+n<time){
                    mp[top.second] = time;
                    top.first--;
                    
                }
                
                if(top.first!=0) temp.push(top);
                if(temp.empty() && pq.empty()) return time;
                time++;
            }
            while(!temp.empty()) pq.push(temp.top()),temp.pop();
        }
        
        return time;
    }
};