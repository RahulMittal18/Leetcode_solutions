#User function Template for python3

class Solution:
    
    #Function to return max value that can be put in knapsack of capacity W.
    def knapSack(self,W, wt, val, n):
        mp={}
    
        def solve(i,N,W,wt,val):
            if i==N:
                return 0
            
            if (i,W) in mp:
                return mp[(i,W)]
            
            not_take = solve(i+1,N,W,wt,val)
            take = float("-inf")
            if W>=wt[i]:
                take = val[i]+solve(i+1,N,W-wt[i],wt,val)
                
            mp[(i,W)] = max(take,not_take)
            return mp[(i,W)]
    
        return solve(0,n,W,wt,val)

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        W = int(input())
        val = list(map(int,input().strip().split()))
        wt = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.knapSack(W,wt,val,n))
# } Driver Code Ends