class Solution {
public:
    int dp[5001][26][26];
    int solve(int i,vector<string> &words,char f,char b){
        if(i==words.size()) return 0;
        
        if(dp[i][f-'a'][b-'a']!=-1) return dp[i][f-'a'][b-'a'];
        
        int c1 = solve(i+1,words,f,words[i].back()) + words[i].size() - (words[i][0]==b);
        int c2 = solve(i+1,words,words[i][0],b) + words[i].size() - (words[i].back()==f);
        return dp[i][f-'a'][b-'a'] = min(c1,c2);
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        memset(dp,-1,sizeof dp);
        char f = words[0][0];
        char b = words[0].back();
        return words[0].size()+solve(1,words,f,b);
    }
};