class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap=0;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(65<=word[i] && word[i]<=90) cap++;
        }
        if(cap==n || cap==0) return true;
        return cap==1 && 65<=word[0] && word[0]<=90;
    }
};