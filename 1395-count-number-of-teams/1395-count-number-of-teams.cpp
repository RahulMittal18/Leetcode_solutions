class Solution {
public:
    int numTeams(vector<int>& r) {
        int n = r.size();
        int ans=0;
        vector<vector<int>> dpi(n,vector<int>(4,0));
        vector<vector<int>> dpd(n,vector<int>(4,0));
        dpi[0][1]=1;
        for(int k=1;k<4;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(k==1) dpi[i][k]=1;
                    else{
                        if(r[i]>r[j]){
                            dpi[i][k] += dpi[j][k-1];
                        }
                    }
                }
            }
        }
        
        
        dpd[0][1]=1;

        for(int k=1;k<4;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(k==1) dpd[i][k]=1;
                    else{
                        if(r[i]<r[j]){
                            dpd[i][k] += dpd[j][k-1];
                        }
                    }
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int k=1;k<4;k++){
        //         cout<<dpd[i][k]<<" \n"[k==3];
        //     }
        // }
        
        
        for(int i=0;i<n;i++){
            ans+=(dpi[i][3]+dpd[i][3]);
        }
        return ans;
    }
};