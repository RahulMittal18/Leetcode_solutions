class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int l=0,r;
        
        if(nums[nums.size()-1]<0){
            r=nums.size();
            l=nums.size()-1;
        }
        else if(nums[0]>=0){
            r=0;
            l=-1;
        }
        else{
            while(l<nums.size()-1){
            if(nums[l+1]>=0 && nums[l]<0)
                break;
            l++;
            }
            r=l+1;
        }
            
        while(l>=0 || r<nums.size()){
            if(l>=0 and r< nums.size()){
                if(-nums[l]<nums[r]){
                    ans.push_back(nums[l]*nums[l]);
                    l-=1;
                }
                else{
                    ans.push_back(nums[r]*nums[r]);
                    r+=1;
                }
            }
            else if(l>=0){
                ans.push_back(nums[l]*nums[l]);
                l-=1;
            }
            else{
                ans.push_back(nums[r]*nums[r]);
                    r+=1;
            }
        }
        return ans;
    }
};