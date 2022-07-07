class Solution {
public:
    int mp[101][101];
    
    bool helper(string s1,string s2,string s3,int i,int j,int m,int n,int r){
        if(i+j==r){
            return (i==m && j==n);
        }
        int k = i+j;
        if(mp[i][j]!=-1) return mp[i][j];
        if(i==m){
            return mp[i][j] = s2[j]==s3[k] ? helper(s1,s2,s3,i,j+1,m,n,r) : false;
        }
        if(j==n){
            return mp[i][j] = s1[i]==s3[k] ? helper(s1,s2,s3,i+1,j,m,n,r) : false;
        }
        bool op1 = false, op2 = false;
        op1 = s2[j]==s3[k] ? helper(s1,s2,s3,i,j+1,m,n,r) : false;
        op2 = s1[i]==s3[k] ? helper(s1,s2,s3,i+1,j,m,n,r) : false;
        return mp[i][j]=op1||op2;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(mp,-1,sizeof mp);
        int m,n,r;
        m=s1.length();
        n=s2.length();
        r=s3.length();
        if(m+n!=r) return false;
        return helper(s1,s2,s3,0,0,m,n,r);
    }
};