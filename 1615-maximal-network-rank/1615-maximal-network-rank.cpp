class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        set<pair<int,int>> s;
        for(auto edge:roads){
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            s.insert({edge[0],edge[1]});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp = indegree[i]+indegree[j];
                if(s.count({i,j})!=0 || s.count({j,i})!=0) temp--;
                ans=max(ans,temp);
            }
        }
        
        return ans;
    }
};