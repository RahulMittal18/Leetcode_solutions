#User function Template for python3

class Solution:
	def compute_value(self, n):
		a = 1
		mod = 1000000007
		for i in range(n):
	         a*=(2*n-i)%mod
	         x=(pow(i+1,mod-2,mod))
	         a=(a*x)%mod
	    return a%mod


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution()
		ans = ob.compute_value(n)
		print(ans)
# } Driver Code Ends