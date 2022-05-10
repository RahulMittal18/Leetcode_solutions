import random
class Solution(object):
    def findKthLargest(self, arr, k):
        x=len(arr)
        def partition(arr,p,r):
            x = arr[r]
            i=p-1
            for j in range(p,r):
                if arr[j]<=x:
                    i+=1
                    arr[i],arr[j]=arr[j],arr[i]
            arr[i+1],arr[r]= arr[r],arr[i+1]
            return i+1
        
        def RP(arr,p,r):
            i = random.randint(p,r)
            arr[r],arr[i]=arr[i],arr[r]
            return partition(arr,p,r)
        
        def RS(arr,p,r,i):
            if p==r:
                return arr[p]
            q = RP(arr,p,r)
            k = q - p + 1
            if i==k:
                return arr[q]
            elif i<k:
                return RS(arr,p,q-1,i)
            else:
                return RS(arr,q+1,r,i-k)
        
        return RS(arr,0,x-1,x-k+1)