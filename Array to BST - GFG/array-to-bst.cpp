// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void BST(vector<int>& nums,vector<int>& ans,int l,int r){
        if(l>r) return;
        int mid = l+ (r-l)/2;
        ans.push_back(nums[mid]);
        BST(nums,ans,l,mid-1);
        BST(nums,ans,mid+1,r);
    }

    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> ans;
        BST(nums,ans,0,nums.size()-1);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends