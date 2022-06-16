class Solution {
public:   
    int maxScoreSightseeingPair(vector<int>& prices) {
        int pro = 0;
        int maxp = -1;
        for(int i=0;i<prices.size();i++){
            pro = max(pro,prices[i]-i+maxp);
            maxp = max(maxp,prices[i]+i);
        }
        return pro;
    }
};