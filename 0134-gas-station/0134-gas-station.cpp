class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int n = gas.size();
        int curr = 0;
        int temp = 0;
        for(int i=0;i<n;i++){
            temp+=gas[i]-cost[i];
            curr+=gas[i]-cost[i];
            // cout<<i<<" "<<curr<<" "<<start<<endl;
            if(curr<0){
                curr=0;
                start=i+1;
            }
        }
        // return start;
        return temp>=0?start:-1;
    }
};