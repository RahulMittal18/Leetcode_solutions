class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> rightOnes(m+1, vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                rightOnes[i][j] = matrix[i][j] == '1' ? 1 + rightOnes[i][j+1] : 0;
            }
        }
        int area = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int k = i;
                int prev = n;
                // if(i==1 && j==2) cout<<k<<endl;
                while(k<m && matrix[k][j]=='1'){
                    prev = min(prev,rightOnes[k][j]);
                    area = max(area, (k-i+1)*prev);
                    // if(i==1 && j==2) cout<<prev<<" "<<area<<endl;
                    k++;
                }
            }
        }
        return area;
    }
};