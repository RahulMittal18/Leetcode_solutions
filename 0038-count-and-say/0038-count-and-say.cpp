class Solution {
public:
    string solve(int n, string s = "1") {
        if(n==1) return s; 

        int i=0, j, len = s.size();
        string res = "";

        while(i<len) {
            j=i;

            while(i<len && s[i]==s[j]) i++;

            res += to_string(i-j) + s[j];
        }

        return solve(n-1, res);
    }
    
    string countAndSay(int n) {
        return solve(n);
    }
};