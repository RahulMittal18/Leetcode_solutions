class Solution {

public:

    int removeDuplicates(vector<int>& nums) {
        

        int count = 0;

        int n = nums.size();
        if(n<2) return n;

        int j = 1;

        int i = 1;

        for (; i < n; i++) {

            if (nums[i] == nums[i-1]) {

                count++;

            }

            else {

                nums[j++] = nums[i];

            }

        }

        return j;

    }

};
      
    
