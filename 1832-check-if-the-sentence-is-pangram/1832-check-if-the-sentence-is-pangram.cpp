class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int>mp;
        for(auto &c:sentence) mp[c]++;
        for(int i=0;i<26;i++){
            if(mp[i+'a']==0) return false;
        }
        return true;
    }
};