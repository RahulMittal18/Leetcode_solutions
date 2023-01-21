#User function Template for python3

class Solution:
    def minVal(self, a, b):
        sets = [0]*32
        count = 0
        for i in range(0,32):
            if (1<<i) & a :
                sets[i] = 1
            if (1<<i) & b :
                count+=1
        num = 0
        if count:
            for i in range(31,-1,-1):
                if sets[i]==1:
                    num |= (1<<i)
                    count-=1
                    if count==0:
                        break
        if count:
            for i in range(0,32):
                if sets[i]!=1:
                    num |= (1<<i)
                    count-=1
                    if count==0:
                        break
        return num
        
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        a = int(input())
        b = int(input())
        
        ob= Solution()
        print(ob.minVal(a,b))
# } Driver Code Ends