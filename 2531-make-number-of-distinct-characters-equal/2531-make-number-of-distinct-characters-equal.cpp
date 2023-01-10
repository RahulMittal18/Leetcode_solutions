class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> fa(26,0),fb(26,0);
        for(auto c:word1) fa[c-'a']++;
        for(auto c:word2) fb[c-'a']++;
        int da = 0;
        int db = 0;
        for(int i=0;i<26;i++){
            if(fa[i]!=0) da++;
            if(fb[i]!=0) db++;
        }        
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(fa[i]==0 || fb[j]==0) continue;
                fa[i]--;
                fb[j]--;
                fa[j]++;
                fb[i]++;
                int da = 0;
                int db = 0;
                for(int k=0;k<26;k++){
                    if(fa[k]!=0) da++;
                    if(fb[k]!=0) db++;
                }
                if(da==db) return true;
                fa[i]++;
                fb[j]++;
                fa[j]--;
                fb[i]--;
            }
        }
        return false;
    }
};