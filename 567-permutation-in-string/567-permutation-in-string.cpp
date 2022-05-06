class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        int arr[26]={0};
        int s[26]={0};
        for(char c:s1){
            s[c-'a']++;
        }
        for(int i=0;i<s1.length();i++)
            arr[s2[i]-'a']++;
        int j=s1.length();
        int i=0;
        bool flag=true;
            for(int i=0;i<26;i++){
                if(s[i]!=arr[i]){
                    flag=false;
                    break;
                }
            }
            if(flag) return true;
        while(j<s2.length()){
            
            arr[s2[i]-'a']--;
            arr[s2[j]-'a']++;
            i++;
            j++;    
            bool flag=true;
            for(int i=0;i<26;i++){
                if(s[i]!=arr[i]){
                    flag=false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};