class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++){
            int l=0,r=numbers.size()-1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(mid!=i and numbers[mid]==target-numbers[i]){
                    return {i+1,mid+1};
                }
                else if(numbers[mid]>target-numbers[i])
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        return {1,1};
    }
};