class Solution {
public:
    int numTeams(vector<int>& r) {
        int n = r.size();
        int ans=0;
        vector<vector<int>> dpi(n,vector<int>(3,0));
        vector<vector<int>> dpd(n,vector<int>(3,0));
        
        dpi[0][0]=1;
        for(int k=0;k<3;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(k==0) dpi[i][k]=1;
                    else{
                        if(r[i]>r[j]){
                            dpi[i][k] += dpi[j][k-1];
                        }
                    }
                }
            }
        }
        
        
        dpd[0][0]=1;
        for(int k=0;k<3;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(k==0) dpd[i][k]=1;
                    else{
                        if(r[i]<r[j]){
                            dpd[i][k] += dpd[j][k-1];
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            ans+=(dpi[i][2]+dpd[i][2]);
        }
        return ans;
    }
};