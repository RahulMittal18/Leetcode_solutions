class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int mod = 1e9 + 7;
        int shift = 0;
        for(int i=1;i<=n;i++){
            int j;
            for(j=31;j>=0;j--){
                if((i&(1<<j))!=0){
                    break;
                }
            }
            shift=(j+1);
            ans = ( i + (ans<<shift)%mod ) % mod;
        }
        return ans;
    }
};