class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        map<int,int> mp;
        vector<int> dp(26,0);
        for(int i=0;i<n;i++){
            int c = s[i]-'a';
            if(mp[c]>0) dp[c]=max(dp[c],1+dp[c]);

            for(int j=0;j<26;j++){
                if(j!=c && abs(c-j)<=k)
                    dp[c]=max(dp[c],1+dp[j]);
            }
            mp[c]++;
            // for(int i=0;i<26;i++) cout<<dp[i]<<" \n"[i==25];

        }
        int ans=0;
        if(k==0) {
            for(auto k:mp) ans=max(ans,k.second);
            return ans;
        }
        return *max_element(dp.begin(),dp.end());
    }
};