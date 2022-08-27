class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int t) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> presum(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                presum[i][j]+=matrix[i][j];
                if(i==0 && j==0){
                    continue;
                }
                if(i>0 && j>0){
                    presum[i][j]-=presum[i-1][j-1];
                }
                if(i>0){
                    presum[i][j]+=presum[i-1][j];
                }
                if(j>0){
                    presum[i][j]+=presum[i][j-1];
                }
            }
        }
        int ans = -100000;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans==t) return t;
                for(int k=i;k<n;k++){
                    for(int l=j;l<m;l++){
                        int temp=presum[k][l];
                        if(i>=0 && j>0){
                            temp-=presum[k][j-1];
                        }
                        if(j>=0 && i>0){
                            temp-=presum[i-1][l];
                        }
                        if(i>0 && j>0){
                            temp+=presum[i-1][j-1];
                        }
                        if(temp<=t){
                            if(ans<temp) ans=temp;
                        }
                    }
                }
            }
        }
        return ans;
    }
};