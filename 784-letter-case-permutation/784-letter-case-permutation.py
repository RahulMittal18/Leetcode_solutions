class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans=[]
        def solve(s,i,temp):
            if i==len(s):
                ans.append("".join(temp))
                return
            if s[i].isalpha():
                c=chr(ord(s[i])^(1<<5))
                solve(s,i+1,temp + [s[i]])
                solve(s,i+1,temp + [c])
            else:
                solve(s,i+1,temp+[s[i]])
        solve(list(s),0,[])
        return ans