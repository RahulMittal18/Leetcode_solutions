class Solution {
public:
    int solve(int n,int p){
        if(n==0) return 1;
        int temp=0;
        for(int i=0;i<5;i++){
            if(i>=p) temp+=solve(n-1,i);
        }
        return temp;
    }
    
    int countVowelStrings(int n) {
        return solve(n,-1);
    }
};