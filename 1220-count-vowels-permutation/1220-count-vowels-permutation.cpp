class Solution {
public:
    unordered_map<char,vector<char>> mp;
    long long int mod = 1e9+7;
    long long solve(int i,int n,vector<vector<int>> &dp,char p){
        if(i==n) return 1;
        if(dp[i][150-p]!=-1) return dp[i][150-p];
        
        long long temp=0;
        for(auto c:mp[p]){
            temp=(0ll+temp+solve(i+1,n,dp,c))%mod;
        }
        return dp[i][150-p]=temp%mod;
    }
    
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n,vector<int>(150,-1));
        mp['A']={'a','e','i','o','u'};
        mp['a']={'e'};
        mp['e']={'a','i'};
        mp['i']={'a','e','o','u'};
        mp['o']={'i','u'};
        mp['u']={'a'};
        return solve(0,n,dp,'A');
    }
};