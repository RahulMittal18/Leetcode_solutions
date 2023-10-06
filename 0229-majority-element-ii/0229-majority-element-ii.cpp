class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0;
        int cand2 = 1;
        int c1 = 0;
        int c2 = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==cand1){
                c1++;
            }
            else if(nums[i]==cand2){
                c2++;
            }
            else if(c1==0){
                cand1 = nums[i];
                c1=1;
            }
            else if(c2==0){
                cand2 = nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1) c++;
        }
        if(c>n/3) ans.push_back(cand1);
        c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand2) c++;
        }
        if(c>n/3) ans.push_back(cand2);
        return ans;
    }
};