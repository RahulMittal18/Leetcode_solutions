class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int last_neg = -1;
        int k = 0;
        int ans = 0;
        int n = nums.size();
        int ncount =0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                k=i+1;
                ncount=0;
                last_neg = -1;
            }
            else if(nums[i]<0){
                ncount++;
                if(last_neg==-1) last_neg = i;
            }
            else if(ncount%2==1) {
                ans = max(ans,i-last_neg);
            }
            
            if(ncount%2==0) ans = max(ans,i-k+1);
        }
        return ans;
    }
};