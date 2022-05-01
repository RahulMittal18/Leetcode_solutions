class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        i=len(s)-1
        j=len(t)-1
        while i>=0 or j>=0:
            c=0
            while i>=0:
                if s[i]=="#":
                    i-=1
                    c+=1
                elif c>0:
                    i-=1
                    c-=1
                else:
                    break
            c=0
            while j>=0:
                if t[j]=="#":
                    j-=1
                    c+=1
                elif c>0:
                    j-=1
                    c-=1
                else:
                    break

            if i>=0 and j>=0:
                if s[i]==t[j]:
                    i-=1
                    j-=1
                else:
                    return False
            elif (i>=0 ) ^ (j>=0):
                return False

        return True
        