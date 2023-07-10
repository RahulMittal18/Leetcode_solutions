class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0;
        int r = 0;
        int trues = 0;
        int falses = 0;
        int ans = 0;
        int n = answerKey.size();
        while(r<n){
            if(answerKey[r]=='T') trues++;
            while(trues>k){
                if(answerKey[l]=='T') trues--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        
        l = 0;
        r = 0;
        while(r<n){
            if(answerKey[r]!='T') falses++;
            while(falses>k){
                if(answerKey[l]!='T') falses--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};