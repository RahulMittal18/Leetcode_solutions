class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i =1;
        int n= nums.size();
        int flag = 0;
        int kahan =-1;
        while(i<n){
            if(nums[i]<nums[i-1]) {
                flag++;
                kahan = i;
            }
            i++;
        }
        if(flag==0) return true;
        if(flag>1) return false;
        if(kahan==1 || kahan == n-1) return true;
        
        for(int i=1;i<n-1;i++){
            int temp = nums[i];
            nums[i]=nums[i-1];
            int c=1;
            for(int i=1;i<n;i++){
                if(nums[i]<nums[i-1]){
                    c=0;
                    break;
                }
            }
            nums[i]=temp;
            if(c) return true;
        }
        
        
        return false;
    }
};