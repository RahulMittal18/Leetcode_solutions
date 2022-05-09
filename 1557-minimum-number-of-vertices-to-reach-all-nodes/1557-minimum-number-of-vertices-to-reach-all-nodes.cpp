class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> arr(n);
        for(auto x:edges){
            arr[x[1]]+=1;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(arr[i]==0) ans.push_back(i);
        }
        return ans;
    }
};