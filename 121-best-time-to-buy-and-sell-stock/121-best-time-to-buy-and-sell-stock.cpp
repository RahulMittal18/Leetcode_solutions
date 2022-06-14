class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0;
        int minp =  100000;
        for(int i=0;i<prices.size();i++){
            minp = min(minp,prices[i]);
            pro = max(pro,prices[i]-minp);
        }
        return pro;
    }
};