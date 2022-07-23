class Solution {
public:
    void mergeSort(vector<pair<int,int>> &arr, vector<pair<int,int>> &temp, int left, int right,vector<int>&ans)
{
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        mergeSort(arr, temp, left, mid,ans);
        mergeSort(arr, temp, mid + 1, right,ans);
  
        merge(arr, temp, left, mid + 1, right,ans);
    }
}
  
void merge(vector<pair<int,int>> &arr, vector<pair<int,int>> &temp, int left, int mid, int right,vector<int>&ans)
{
    int i, j, k;
    int count = 0;
  
    i = left;
    j = mid; 
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i].first <= arr[j].first) {
            ans[arr[i].second]+=count;
            temp[k++] = arr[i++];
        }
        else {
            count++;
            temp[k++] = arr[j++];
        }
    }
  
    while (i <= mid - 1){
        ans[arr[i].second]+=count;
        temp[k++] = arr[i++];
    }
  
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
  
}

    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr(n),temp(n);
        for(int i=0;i<n;i++){
            arr[i].first=nums[i];
            arr[i].second=i;        
        }
        vector<int> ans(n,0);
        mergeSort(arr,temp,0,n-1,ans);
        return ans;
    }
};