class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        
        st1=[]
        st2=[]
        for c in s:
            if len(st1) and c=="#":
                st1.pop()
            elif c!="#":
                st1.append(c)
        
        for c in t:
            if len(st2) and c=="#":
                st2.pop()
            elif c!="#":
                st2.append(c)
        
        return "".join(st1)=="".join(st2)
        