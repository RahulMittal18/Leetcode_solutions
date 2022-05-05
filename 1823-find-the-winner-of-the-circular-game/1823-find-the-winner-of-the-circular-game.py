class Solution(object):
    def findTheWinner(self, n, k):
        arr=[i for i in range(1,n+1)]
        def helper(arr,k):
            # print(arr)
            if len(arr)==1:
                return arr[0]
            # if len(arr)==2:
            #     return arr[0] if k%2==0 else arr[1]
            l=k%len(arr)
            temp = arr[l:]
            if l==0:
                temp=arr[:len(arr)-1]
            else:
                temp=arr[l:]+arr[:l-1]
            
            return helper(temp,k)
        
        return helper(arr,k)
            