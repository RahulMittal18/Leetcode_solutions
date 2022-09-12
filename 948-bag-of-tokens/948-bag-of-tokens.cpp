class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int l = 0;
        int r = n-1;
        int score = 0;
        int ans = 0;
        while(l<=r){
            if(power>=tokens[l]){
                power-=tokens[l];
                score++;
                l++;
            }
            else if(score>=1){
                power+=tokens[r];
                score--;
                r--;
            }
            else{
                r--;
            }
            ans = max(ans,score);
        }
        return ans;
    }
};