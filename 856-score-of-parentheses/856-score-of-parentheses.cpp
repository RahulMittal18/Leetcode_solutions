class Solution {
public:
    int scoreOfParentheses(string s) {
        int bf=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c=='(') bf++;
            else{
                bf--;
                if(s[i-1]!=')') ans+=(1<<bf);
            }
        }
        return ans;
    }
};