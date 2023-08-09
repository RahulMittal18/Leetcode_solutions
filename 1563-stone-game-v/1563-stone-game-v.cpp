class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> sums(n+1, 0);
        int sum = 0;
        for(int i = 0; i<n; ++i){
            sum += stoneValue[i];
            sums[i+1] = sum;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        return findOpt(0, n-1, sums, dp);
    }
    int findOpt(int left, int right, vector<int>& sums, vector<vector<int>>& dp){
        //avoid duplicated searches
        if(dp[left][right]!=0) return dp[left][right];
        int res = 0;
        for(int i = left; i < right; i++){
            int lsum = sums[i+1]-sums[left];
            int rsum = sums[right+1]-sums[i+1];
            //cut branches
            if(lsum<rsum){
                res = max(res, lsum+findOpt(left, i, sums, dp));
            }
            else if(lsum>rsum){
                res = max(res, rsum+findOpt(i+1, right, sums, dp));
            }
            else{
                res = max(res, lsum+findOpt(left, i, sums, dp));
                res = max(res, rsum+findOpt(i+1, right, sums, dp));
            }
        }
        //fill your dp once you finished this sub-tree
        dp[left][right] = res;
        return res;
    }
};