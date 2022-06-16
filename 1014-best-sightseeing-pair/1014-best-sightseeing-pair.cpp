class Solution {
public:
    int n;
    int solve(vector<int>& values,int i,int number,vector<vector<int>> &dp){
        if(number>=2) return 0;
        if(i>=n) return INT_MIN;
        
        if(dp[i][number]!=-1) return dp[i][number];
        
        if(number==0){
            return dp[i][number] = max(i+values[i]+ solve(values,i+1,number+1,dp),solve(values,i+1,number,dp));
        }
        else{
            return dp[i][number] = max(-i+values[i]+ solve(values,i+1,number+1,dp),solve(values,i+1,number,dp));
        }
    }
    
    int maxScoreSightseeingPair(vector<int>& values) {
        n=values.size();
        vector<vector<int>> dp(n,vector<int> (3,-1));
        // 0 for first and 1 for second
        return solve(values,0,0,dp);
    }
};