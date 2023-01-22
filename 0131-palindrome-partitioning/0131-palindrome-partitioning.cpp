class Solution {
public:
    
    void solve(int i,int n,string &s,vector<string>&temp,vector<vector<string>>&ans){
        if(i==n) {
            ans.push_back(temp);
            return;
        }
        
        for(int k=i;k<n;k++){
            bool flag = true;
            int l = i;
            int r = k;
            while(l<=r){
                if(s[l++]!=s[r--]){
                    flag = false;
                    break;
                }
            }
            if(flag) {
                temp.push_back(s.substr(i,k-i+1));
                solve(k+1,n,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,n,s,temp,ans);
        return ans;
    }
};