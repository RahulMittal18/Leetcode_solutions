class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            for(j=0;j<min(strs[0].size(),strs[i].size());j++){
                if(strs[i][j]!=ans[j]) break;
            }
            ans = ans.substr(0,j);
        }
        return ans;
    }
};