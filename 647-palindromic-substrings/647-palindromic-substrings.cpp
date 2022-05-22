class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0; i<s.length(); i++){
            // for odd length palindromes
            int l=i,r=i;
            while(l>=0 and r<s.length() and s[l]==s[r]){
                ans++;
                l--;
                r++;
            }
            
            // for even length palindromes
            l=i;
            r=i+1;
            while(l>=0 and r<s.length() and s[l]==s[r]){
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};