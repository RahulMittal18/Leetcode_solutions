class Solution {
public:
        int numDecodings(string s) {
        if (s.empty()) return 0;
        memo = vector<int>(s.size(), -1);
        return ways(s);
    }
    
    int ways(string s, int i = 0) {
        if (i == s.size()) return 1;
        if (i > s.size()) return 0;
        if (memo[i] >= 0) return memo[i];        
        if (s[i] == '0') return memo[i] = 0;
        if (stoi(s.substr(i,2)) <= 26) return memo[i] = ways(s, i+1) + ways(s, i+2);
        return memo[i] = ways(s, i+1);
    }
    
    vector<int> memo;
};