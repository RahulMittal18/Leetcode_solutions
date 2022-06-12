class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        ans=[0]*k
        res=float("inf")
        def solve(i,ans):
            nonlocal res
            if i==len(cookies):
                x = max(ans)
                res = min(x,res)
                return
            if res<max(ans):
                return
            for j in range(k):
                ans[j]+=cookies[i]
                solve(i+1,ans)
                ans[j]-=cookies[i]
                
            
        solve(0,ans)
        return res