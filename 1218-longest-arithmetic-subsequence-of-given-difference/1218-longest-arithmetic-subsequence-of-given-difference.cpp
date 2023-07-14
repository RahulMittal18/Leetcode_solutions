class Solution {
public:
    // int bs(vector<int>&arr, int end,int x){
    //     int l = 0;
    //     int r = end-1;
    //     while(l<=r){
    //         int mid = l + (r-l)/2;
    //         if(arr[mid]==x){
    //             return mid;
    //         }
    //         else if(arr[mid]<x){
    //             l=mid+1;
    //         }else r = mid-1;
    //     }
    //     return end;
    // }
    
    
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        vector<int> dp(n,1);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x = arr[i]-diff;
            if(mp.count(x)){
                dp[i]=1+dp[mp[x]];
            }
            mp[arr[i]]=i;
        }
        int x = *max_element(dp.begin(),dp.end());
        return x;
    }
};