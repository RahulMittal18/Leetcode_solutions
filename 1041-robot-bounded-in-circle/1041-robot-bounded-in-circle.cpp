class Solution {
public:
    bool isRobotBounded(string instructions) {
        set<pair<int,int>> s;
        // north east south west
        int d =0;
        int a=0;
        int b=0;
        vector<vector<int>> v = {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<instructions.size();i++){
            if(instructions[i]=='R'){
                d = (d+1)%4;
            }
            else if(instructions[i]=='L'){
                d = (d+3)%4;
            }
            else{
                a+=v[d][0];
                b+=v[d][1];

            }
            
        }
        return (a==0 and b==0)  or d>0;
    }
};