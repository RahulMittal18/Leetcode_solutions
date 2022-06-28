class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int row = m.size()-1;
        int col = m[0].size()-1;
        int i =0;
        int j= 0;
        vector<int> ans;
        while(i<=row && j<=col){
            if(i<=row && j<=col){
            for(int k=j;k<=col;k++) ans.push_back(m[i][k]);
            i++;}
            if(i<=row && j<=col){
            for(int k=i;k<=row;k++) ans.push_back(m[k][col]);
            col--;}
            if(i<=row && j<=col){
            for(int k=col;k>=j;k--) ans.push_back(m[row][k]);
            row--;}
            if(i<=row && j<=col){
            for(int k=row;k>=i;k--) ans.push_back(m[k][j]);
            j++;}
        }
        return ans;
    }
};