// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(minheap.empty() and maxheap.empty())
        {
            maxheap.push(x);
        }
        else
        {
            if(maxheap.top() < x)
            {
                minheap.push(x);
            }
            else
            {
                maxheap.push(x);
            }
        }
        
        int n = maxheap.size();
        int m = minheap.size();
        
        if(abs(n - m) == 2)
        {
            if(n > m)
            {
                int ele = maxheap.top();
                maxheap.pop();
                minheap.push(ele);
            }
            else
            {
                int ele = minheap.top();
                minheap.pop();
                maxheap.push(ele);
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        int n = maxheap.size();
        int m = minheap.size();
        
        if((n+m)%2 == 0)
        {
            return ((double)minheap.top() + (double)maxheap.top())/2.0;
        }
        else
        {
            if(n > m) return maxheap.top();
            else return minheap.top();
        }
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends