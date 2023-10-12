/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int low = 0;
        int high = n-1;
        int peak = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int mide = arr.get(mid);
            if(mid<n-1 && (mid==0 || (mid>0 && mide>arr.get(mid-1))) && mide<arr.get(mid+1)){
                    low = mid+1;
            }
            else if(mid>0 && mide<arr.get(mid-1) && (mid==n-1 || (mid<n-1 && mide>arr.get(mid+1)))){
                    high = mid-1;
            }
            else{
                peak = mid;
                break;
            }
        }

        if(arr.get(peak)==target) return peak;
        low = 0;
        high = peak-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int mide = arr.get(mid);
            if(mide==target) return mid;
            else if(mide>target) high = mid-1;
            else low = mid+1;
        }
        low = peak+1;
        high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int mide = arr.get(mid);
            if(mide==target) return mid;
            else if(mide<target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};