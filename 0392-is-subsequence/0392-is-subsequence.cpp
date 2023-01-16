class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0)
            return true;
        if(t.length()==0)
            return false;
        
        int i=0;
        int j=0;
        while(j<t.length()){
            if(s[i]==t[j])
                i++;
            if(i==s.length())
                break;
            j++;
            // cout<<s[i]<<t[j]<<endl;
        }
        if(j==t.length()) return false;
        return true;
            
        
    }
};