class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        unordered_map<int,int> mp;
        for(int j=0;j<points.size();j++){
            mp[points[j][0]]++;
        }
        for(int j=0;j<points.size();j++){
            for(int i=j+1;i<points.size();i++){
                int num = points[i][1]-points[j][1];
                int den = points[i][0]-points[j][0];
                int curr = 2;
                if(den==0) continue;
                for(int k=0;k<points.size();k++){
                    if(i!=k && j!=k){
                        int n = points[k][1]-points[j][1];
                        int d = points[k][0]-points[j][0];
                        if(d*num==n*den) curr++;    
                    }
                }
                ans=max(ans,curr);
            }
        }
        for(auto k:mp){
            ans = max(ans,k.second);
        }
        return ans;
    }
};