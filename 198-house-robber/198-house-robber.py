class Solution(object):
    def rob(self, nums):
        hm={}
        def solve(i,nums):
            if i>=len(nums):
                return 0
            if i in hm:
                return hm[i]
            else:
                hm[i]=max(solve(i+1,nums),solve(i+2,nums)+nums[i])
                return hm[i]
        return solve(0,nums)