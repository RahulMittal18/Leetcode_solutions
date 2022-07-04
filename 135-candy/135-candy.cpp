class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) ans[i]=ans[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                ans[i]=max(ans[i],1+ans[i+1]);
            }
        }

        int res = accumulate(ans.begin(),ans.end(),0);
        return res;
    }
};