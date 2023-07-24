class Solution {
public:
    double myPow(double x, int nn) {
        double ans = 1;
        double fac = x;
        long long n = nn;
        if(n<0) fac=1/x,n=-1*n;
        while(n>0){
            if(n&1) ans*=fac;
            fac*=fac;
            n>>=1;
        }
        return ans;
    }
};