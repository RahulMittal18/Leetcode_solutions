class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xored = 0;
        for(int i=1;i<=n;i++){
            xored^=i;
        }
        for(int i=0;i<n;i++){
            xored^=nums[i];
        }
        int nn = xored;
        int bit = log2(nn&~(nn-1));
        int c=0;
        int nc=0;
        for(int i=0;i<n;i++){
            if((nums[i]&(1<<bit))!=0) c^=nums[i];
            else nc^=nums[i];
        }
        for(int i=1;i<=n;i++){
            if((i&(1<<bit))!=0) c^=i;
            else nc^=i;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == c)
                return {c, nc};
        }
        
        return {nc,c};
    }
};