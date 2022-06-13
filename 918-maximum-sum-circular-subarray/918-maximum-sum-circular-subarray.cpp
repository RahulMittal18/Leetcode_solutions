class Solution {
public:
   
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxans = INT_MIN;
        int minans = INT_MAX;
        int minsum = 0;
        int maxsum = 0;
        int totalsum = 0;
        for(int& x:nums){
            totalsum+=x;
            maxsum = max(x,x+maxsum);
            maxans = max(maxans,maxsum);
            minsum = min(minsum+x,x);
            minans = min(minans,minsum);
        }
        
        return totalsum==minans?maxans:max(totalsum-minans,maxans);
    }
};