class Solution {
public:  
    long dp[16][2];
    long solve(int idx, bool tight,string &s,string &suff,int mxl){
        if (idx == s.size()) return 1;
        
        if (dp[idx][tight] != -1) 
            return dp[idx][tight];

        long ans = 0;
        if(s.size()<suff.size()) return 0;
        int limit;
        
        if(idx<s.size()-suff.size()){
            if(tight) limit=min(mxl,s[idx]-'0');
            else limit=mxl;
            // cout<<limit<<endl;
            for(int i=0;i<=limit;i++){   
                int ntight = ((i==s[idx]-'0') && tight)? 1 : 0;
                ans= (ans+solve(idx+1,ntight,s,suff,mxl));  
            }
        }
        else{
            if(tight) limit=min(mxl,s[idx]-'0');
            else limit = mxl;
            int ntight = tight;
            cout<<idx<<" "<<tight<<" "<<limit<<" "<<((suff[idx-s.size()+suff.size()])-'0')<<endl;
            if(suff[idx-s.size()+suff.size()]-'0'<s[idx]-'0') ntight=0;
            if(limit>=((suff[idx-s.size()+suff.size()])-'0')){
                ans= (ans+solve(idx+1,ntight,s,suff,mxl)); 
            }
            // cout<<idx<<"uuu"<<limit<<" "<<(suff[idx-s.size()+suff.size()]-'0')<<endl;
        }
        
        return dp[idx][tight] = ans;
    }

    
    long long numberOfPowerfulInt(long long low, long long high, int limit, string s) {
        memset(dp, -1, sizeof(dp));
        low--;
        string h  = to_string(high);
        string l  = to_string(low);
        long upper = solve(0,1,h,s,limit);
        memset(dp, -1, sizeof(dp));
        // long lower = 0;
        long lower = solve(0,1,l,s,limit);
        // cout<<upper<<" "<<lower<<endl;
        return (upper - lower);
    }
};