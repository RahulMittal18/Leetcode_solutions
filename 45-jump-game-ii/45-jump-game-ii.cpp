class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2) return 0;   //base case
        int jump=1,n=nums.size(),currjmp=nums[0],mxjmp=nums[0];
        int i=0;
		
        while(i<n-1)
        {
            mxjmp=max(mxjmp,i+nums[i]);
             
            if(currjmp==i) //we have to take jump now because our currjump now ends.
            {
                jump++;//increment in jump
                currjmp=mxjmp; //assign new maxjmp to currjmp
            }
            i++;
        }
        return jump;
    }
};