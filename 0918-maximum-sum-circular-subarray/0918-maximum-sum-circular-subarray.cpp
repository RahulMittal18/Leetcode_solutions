class Solution {
public:
    
    int kadane1(vector<int> arr){
        int ans = INT_MIN;
        int sum=0;
        for(int x:arr){
            sum = max(x,x+sum);
            ans = max(ans,sum);
        }
        return ans;
    }
    
    
    int kadane2(vector<int> arr){
        int ans = INT_MAX;
        int sum=0;
        for(int x:arr){
            sum = min(x,x+sum);
            ans = min(ans,sum);
        }
        return ans;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int a1 = kadane1(nums);
        int a2 = kadane2(nums);
        int a3 = accumulate(nums.begin(),nums.end(),0ll);
        return a3-a2!=0?max(a1,a3-a2):a1;
    }
};