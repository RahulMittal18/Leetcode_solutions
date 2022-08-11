class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> temp(numRows,vector<char> (s.size(),'#'));
        
        int i=0,j=0;
        bool up=false;
        for(auto &c: s){
            temp[i][j]=c;
            if(!up){
                if(i<numRows-1) i++;
                else up = true; 
            }
            if(up) {
                i--;
                j++;
                if(i==0) up=false;
            }
            
        }
        string ans(s.size(),'a');
        int k=0;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.size();j++){
                if(temp[i][j]!='#') ans[k++] = (temp[i][j]);
            }
        }
        return ans;
    }
};