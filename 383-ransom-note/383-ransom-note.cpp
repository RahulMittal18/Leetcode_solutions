class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26,0);
        for(auto &c:magazine){
            cnt[c-'a']++;
        }
        for(auto &c: ransomNote){
            cnt[c-'a']--;
            if(cnt[c-'a']<0) return false;
        }
        return true;
    }
};