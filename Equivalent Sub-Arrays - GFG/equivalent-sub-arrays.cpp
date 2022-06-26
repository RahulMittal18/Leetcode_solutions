// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int nums[], int n)
    {
        unordered_set<int> s;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) s.insert(nums[i]);
        int size = s.size();
        int l=0;
        int i =0;
        int count = 0;
        int ans=0;
        while(i<n){
            if(mp[nums[i]]==0) count++;
            mp[nums[i]]++;
            while(count==size){
                // cout<<l<<" "<<i<<" "<<n-i<<endl;
                ans+=(n-i);
                mp[nums[l]]--;
                if(mp[nums[l]]==0) count--;
                l++;
            }
            i++;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends