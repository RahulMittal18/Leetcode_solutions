class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int ans = 0;
        char prev = '#';
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='I'){
                if(prev=='X' || prev=='V') ans-=mp[s[i]];
                else ans+=mp[s[i]];
            }
            else if(s[i]=='X'){
                if(prev=='L' || prev=='C') ans-=mp[s[i]];
                else ans+=mp[s[i]];
            }
            else if(s[i]=='C'){
                if(prev=='D' || prev=='M') ans-=mp[s[i]];
                else ans+=mp[s[i]];
            }
            else{
                ans+=mp[s[i]];
            }
            prev = s[i];
        }
        return ans;
    }
};