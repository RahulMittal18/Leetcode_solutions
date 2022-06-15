class Solution {
public:
    static bool cmp(string& w1,string& w2){
        return w1.size()<w2.size();
    }
    
    bool check(string &w1,string &w2){
        if(w1.size()!=1+w2.size()) return false;
        int f=0;
        int s=0;
        while(f<w1.size()){
            if(w1[f]==w2[s]){
                f++;
                s++;
            }
            else{
                f++;
            }
        }
        if(f==w1.size() and s==w2.size()) return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        vector<int> dp(n,1);
        int ans =1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(check(words[i],words[prev]) and 1+dp[prev]>dp[i]) dp[i]=1+dp[prev];
                ans=max(dp[i],ans);
            }
        }
        return ans;
    }
};