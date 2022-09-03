class Solution {
public:
    
    void solve(int n,int k,int prev,string &temp,vector<int> &ans){
        if(n==0){
            ans.push_back(stoi(temp));
            return;
        }
        for(int i=0;i<=9;i++){
            if(abs(prev-i)==k){
                temp.push_back('0'+i);
                solve(n-1,k,i,temp,ans);
                temp.pop_back();
            }
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        string temp="";
        for(int i=1;i<=9;i++){
            temp.push_back(i+'0');
            solve(n-1,k,i,temp,ans);
            temp.pop_back();
        }
        return ans;
    }
};