class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> left(n,vector<int> (n,1));
        vector<vector<int>> top(n,vector<int> (n,1));
        vector<vector<int>> bottom(n,vector<int> (n,1));
        vector<vector<int>> right(n,vector<int> (n,1));                         
        vector<vector<int>> block(n,vector<int> (n,1));

        for(auto e:mines){
            block[e[0]][e[1]]=0;
        } 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(block[i][j]==0) left[i][j]=0;
                else
                if(j>0) left[i][j]=left[i][j-1]+1;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(block[i][j]==0) right[i][j]=0;
                else
                if(j<n-1) right[i][j]=right[i][j+1]+1;
            }
        }
        
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(block[i][j]==0) top[i][j]=0;
                else
                if(i>0) top[i][j]=top[i-1][j]+1;
            }
        }
        for(int j=n-1;j>=0;j--){
            for(int i=n-1;i>=0;i--){
                if(block[i][j]==0) bottom[i][j]=0;
                else
                if(i<n-1) bottom[i][j]=bottom[i+1][j]+1;
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,min({top[i][j],bottom[i][j],left[i][j],right[i][j]}));
            }
        }
        return ans;
    }
};