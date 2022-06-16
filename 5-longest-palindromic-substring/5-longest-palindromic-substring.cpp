class Solution {
public:
    int n;
    int l=0,r=0; // to store starting and ending index of palindromic substring
    
    // function to find even length palindrome from middle indexes
    void evenPalindrome(string &s,int i,int j){
        while(i>=0 and j<n and s[i]==s[j]){
                i--;
                j++;
        }
        if(j-i-1>r-l+1){
            l=i+1;
            r=j-1;
        }
    }
    
    // function to find odd length palindrome from middle indexes
    void oddPalindrome(string &s,int i,int j){
        while(i>=0 and j<n and s[i]==s[j]){
                i--;
                j++;
        }
        if(j-i-1>r-l+1){
            l=i+1;
            r=j-1;
        }
    }
    
    string longestPalindrome(string s) {
        n=s.size();
        for(int i=0;i<n;i++){
            evenPalindrome(s,i,i+1);
            oddPalindrome(s,i,i);
        }
        return s.substr(l,r-l+1);
    }
};