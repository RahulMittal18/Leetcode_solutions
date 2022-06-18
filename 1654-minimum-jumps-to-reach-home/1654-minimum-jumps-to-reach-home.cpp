class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int,int>> q;
        set<int> vis;
        int m=-1;
        for(auto xx:forbidden){
            vis.insert(xx);
            m=max(m,xx);
        }
        int r = max(x,m)+a+b;
        // 1 for backward , 0 for forward
        q.push({0,0});
        int ans=0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto f = q.front();
                q.pop();
                if(f.first==x) return ans;
                if(vis.find(f.first)!=vis.end()) continue;
                if(f.second==0)
                vis.insert(f.first);

                if(f.first+a<=r){
                    q.push({f.first+a,0});
                }
                if(f.second==0 && f.first-b>=0){
                    q.push({f.first-b,1});
                }   
            }
            ans++;
        }
        return -1;
    }
};