class Solution {
public:
    long long solve(unordered_map<char,vector<char>> &mp,int i,int n,vector<vector<int>> &dp,char p){
        if(i==n) return 1;
        if(dp[i][p-'a']!=-1) return dp[i][p-'a'];
        
        long long temp=0;
        int mod = 1e9+7;
        for(auto c:mp[p]){
            temp=(temp+solve(mp,i+1,n,dp,c))%(mod);
        }
        return dp[i][p-'a']=temp;
    }
    
    int countVowelPermutation(int n) {
        unordered_map<char,vector<char>> mp;
        vector<vector<int>> dp(n,vector<int>(26,-1));
        mp['b']={'a','e','i','o','u'};
        mp['a']={'e'};
        mp['e']={'a','i'};
        mp['i']={'a','e','o','u'};
        mp['o']={'i','u'};
        mp['u']={'a'};
        return solve(mp,0,n,dp,'b');
    }
};