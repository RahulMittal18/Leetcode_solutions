class Solution {
public:
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(isPalindrome(s)) return 1;
        else return 2;
    }
};