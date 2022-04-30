class Solution(object):
    def longestPalindromeSubseq(self, s):
        mp={}
        def helper(s,i,j):
            if i>j:
                return 0
            if i==j:
                mp[(i,j)]=1
                return 1
            if (i,j) in mp:
                return mp[(i,j)]
            
            if s[i]==s[j]:
                mp[(i,j)] = 2+ helper(s,i+1,j-1)
                return mp[(i,j)]
            else:
                x=(helper(s,i+1,j))
                y=(helper(s,i,j-1))
                mp[(i,j)]=max(x,y)
                return mp[(i,j)]
        
        helper(s,0,len(s)-1)
        return mp[(0,len(s)-1)]