class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1) return 0;
        if(k&1) return kthGrammar(n,(k+1)/2);
        return 1-kthGrammar(n,(k+1)/2);
    }
};