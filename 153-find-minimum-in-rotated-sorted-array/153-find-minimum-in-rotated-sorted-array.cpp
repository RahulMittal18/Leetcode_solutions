class Solution {
public:
    int findMin(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        while(l<r){
            if(arr[l]<arr[r]) return arr[l];
            int mid = l + (r-l)/2;
            if(arr[mid]<arr[r])
                r=mid;
            else
                l=mid+1;
        }
        return arr[l];
    }
};