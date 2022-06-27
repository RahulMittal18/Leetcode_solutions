class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char s:n){
            ans = max(ans,s-'0');
        }
        return ans;
    }
};