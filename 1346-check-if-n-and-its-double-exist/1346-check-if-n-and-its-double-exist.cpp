class Solution {
public:
    
    int bs(vector<int> arr,int l,int r,int target){
        while(l<=r){
            int mid= l + (r-l)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
    
    
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int res = bs(arr,0,arr.size()-1,2*arr[i]);
            if( res!= i and res!=-1)
                return true;
        }
        return false;
    }
};