class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector < pair<int,int> > pq;
        for(int i=0;i<mat.size();i++){
            int l=0,r=mat[0].size()-1;
            int no=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(mat[i][mid]==1){
                    no=mid;
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            pq.push_back({no,i});
        }
        sort(pq.begin(),pq.end());
        vector<int> ans;
        int i=0;
        while(k--){
            ans.push_back(pq[i].second);
            i++;
        }
        return ans;
    }
};