class Solution {
public:
    
    bool check(vector<int>&nums,int mid,int p){
        int x = 0;
        int n = nums.size();
        int i=1;
        while(i<n){
            if(nums[i]-nums[i-1]<=mid){
                x++;
                i++;
            }
            i++;
        }
        return x>=p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long l =0,r=1e18;
        long long ans = 1e18;
        while(l<=r){
            long long mid = l+(r-l)/2;
            // cout<<mid<<endl;
            if(check(nums,mid,p)){
                ans = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};