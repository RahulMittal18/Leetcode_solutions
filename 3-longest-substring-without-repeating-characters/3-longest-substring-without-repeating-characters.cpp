class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int ans=0;
        map<char,int> mp;
        while(r<s.length()){
            if(mp[s[r]]==0){
                mp[s[r]]+=1;
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                while(s[l]!=s[r]){
                    mp[s[l]]-=1;
                    l++;
                }
                l++;
                r++;
            }
            
        }
        return ans;
    }
};