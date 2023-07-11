class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n,0);
        int d = 0;
        int i=0;
        // while(nums[i]==0) i++;
        for(;i<n;i++){
            // if(i==n-k){
            //     bool flag = true;
            //     for(int j=i;j<n;j++) if(nums[j]!=d) return false;
            //     return true;
            // }
            if(d>nums[i]) return false;
            nums[i]-=d;
            d += nums[i];
            diff[i] = nums[i];
            if(i-k+1>=0) d-=diff[i-k+1];
        }
        return d==0;
    }
};