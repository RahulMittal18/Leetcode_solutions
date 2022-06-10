class Solution {
public:
    int singleNumber(vector<int>& A) {
        int a[32]={0}; 
    for(int i=0;i<32;i++){
        for(int j=0;j<A.size();j++){
            if(A[j]&(1<<i)) a[i]++;
        }
    }
    int x=0; 
    for(int i=0;i<32;i++){
        if(a[i]%3) x+=(1<<i);
    }
    return x;
    }
};