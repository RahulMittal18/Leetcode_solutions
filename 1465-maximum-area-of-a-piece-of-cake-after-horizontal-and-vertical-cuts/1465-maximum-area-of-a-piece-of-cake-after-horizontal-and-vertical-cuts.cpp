class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int mod = 1e9 + 7;
        int m = hc.size();
        int n = vc.size();
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int maxH = max(hc[0],h-hc[m-1]);
        int maxW = max(vc[0],w-vc[n-1]);
        
        for(int i=1;i<m;i++){
            maxH = max(maxH,hc[i]-hc[i-1]);
        }
        for(int j=1; j<n;j++){
            maxW = max(maxW,vc[j]-vc[j-1]);
        }
        return int(((long long)maxH*(long long)maxW)%mod);        
    }
};