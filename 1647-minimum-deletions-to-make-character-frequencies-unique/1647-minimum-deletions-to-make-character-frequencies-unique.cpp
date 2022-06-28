class Solution {
public:
    int minDeletions(string s) {
        int freq[26]={0};
        for(char c:s) freq[c-'a']++;
        map<int,set<char>> mp;
        for(int i=0;i<26;i++) mp[freq[i]].insert(i+'a');
        int ans = 0;
        mp[0].clear();
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                if(mp[freq[i]].size()!=1){
                    mp[freq[i]].erase(i+'a');
                    while(mp[freq[i]].size()!=0){
                        ans++;
                        freq[i]--;
                    }
                    if(freq[i]!=0)
                    mp[freq[i]].insert(i+'a');
                }
            }
        }
        return ans;
    }
};