class Solution {
public:
    unordered_map<string,bool> mp;
    
    bool helper(string s1,string s2,string s3,int i,int j,int k,int m,int n,int r){
        if(k==r){
            return (i==m && j==n);
        }
        string key = to_string(i) + "-" + to_string(j) + "-" + to_string(k);
        if(mp.find(key)!=mp.end()) return mp[key];
        if(i==m){
            return mp[key] = s2[j]==s3[k] ? helper(s1,s2,s3,i,j+1,k+1,m,n,r) : false;
        }
        if(j==n){
            return mp[key] = s1[i]==s3[k] ? helper(s1,s2,s3,i+1,j,k+1,m,n,r) : false;
        }
        bool op1 = false, op2 = false;
        op1 = s2[j]==s3[k] ? helper(s1,s2,s3,i,j+1,k+1,m,n,r) : false;
        op2 = s1[i]==s3[k] ? helper(s1,s2,s3,i+1,j,k+1,m,n,r) : false;
        return mp[key]=op1||op2;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        int m,n,r;
        m=s1.length();
        n=s2.length();
        r=s3.length();
        if(m+n!=r) return false;
        return helper(s1,s2,s3,0,0,0,m,n,r);
    }
};